//
//  IDOBluetoothServices.h
//  VeryfitSDK
//
//  Created by apple on 2018/8/22.
//  Copyright © 2018年 hedongyang. All rights reserved.
//

#import <Foundation/Foundation.h>
#if __has_include(<IDOBlueProtocol/IDOBlueProtocol.h>)
#else
#import "IDOGetInfoBluetoothModel.h"
#endif

// 蓝牙扫描、连接状态通知监听名字 | Bluetooth scan, connection status notification listener name
extern NSString * _Nonnull IDOBluetoothConnectStateNotifyName;

// 蓝牙扫描、连接过程错误通知监听名字 | Bluetooth scan, connection process error notification listener name
extern NSString * _Nonnull IDOBluetoothConnectErrorNotifyName;

// 蓝牙主动断开通知监听名字,多在配对和固件升级使用 | Bluetooth disconnect notification listener name
extern NSString * _Nonnull IDOBluetoothDisconnectNotifyName;

// 蓝牙主动发送ping通知，用与app的保活，保证alexa等功能的使用 | Bluetooth ping notification listener name
extern NSString * _Nonnull IDOBluetoothPingNotifyName;

// 蓝牙多运动数据暂停开启结束通知 | Bluetooth SwitchActivity notification listener name
extern NSString * _Nonnull IDOBluetoothSwitchActivityNotifyName;

//固件重启后重连发送通知
extern NSString * _Nonnull IDOBluetoothFirmwareRebootNotifyName;

//设备Alexa空闲超过1h发送通知
extern NSString * _Nonnull IDOBluetoothAlexaIdleMoreThan1hNotifyName;

//设备Alexa音量0或100的通知
extern NSString * _Nonnull IDOBluetoothAlexaFirmwareVolumeNotifyName;

// 蓝牙主动开始扫描通知监听名字,多在配对和固件升级使用 | Bluetooth start scan notification listener name
extern NSString * _Nonnull IDOBluetoothStartScanNotifyName;

// 蓝牙主动停止扫描通知监听名字,多在配对和固件升级使用 | Bluetooth stop scan notification listener name
extern NSString * _Nonnull IDOBluetoothStopScanNotifyName;

// 当前连接的手环设备为OTA模式通知监听名字 | The currently connected bracelet device is OTA mode notification listener name
extern NSString * _Nonnull IDOBluetoothOtaModeNotifyName;

// 蓝牙日志打开记录通知名字 | Bluetooth log opens record notification name
extern NSString * _Nonnull IDOBluetoothOpenLogRecordNotifyName DEPRECATED_MSG_ATTRIBUTE("this attribute is discarded");

// 数据迁移状态通知名字 | Data migration status notification name
extern NSString * _Nonnull IDOBluetoothDataMigrationNotifyName DEPRECATED_MSG_ATTRIBUTE("this attribute is discarded");

// 设备绑定状态通知名字 | device bind status notification name
extern NSString * _Nonnull IDOBluetoothDeviceBindNotifyName;

// 同步配置获取设备信息通知名字 | get device info notification name
extern NSString * _Nonnull IDOBluetoothGetDeviceInfoNotifyName;

// 同步配置完成通知名字 | sync config complete notification name
extern NSString * _Nonnull IDOBluetoothSyncConfigNotifyName;

// 同步健康数据完成通知名字 | sync health data complete notification name
extern NSString * _Nonnull IDOBluetoothSyncHealthNotifyName;

// 刚连接时快速配置完成通知名字 | fast sync complete notification name
extern NSString * _Nonnull IDOBluetoothFastSyncNotifyName;

// 同步全部配置完成通知名字 | sync all config complete notification name
extern NSString * _Nonnull IDOBluetoothSyncAllConfigNotifyName;

// 设备固件版本改变通知名字 | device firmware version change notification name
extern NSString * _Nonnull IDOBluetoothDeviceVersionNotifyName;

// 蓝牙连接同步配置主动获取固件BT连接状态改变通知名字 | device bt state change notification name
//object -》NSNumber: 0 （disconnect），1 (connect)
extern NSString * _Nonnull IDOBluetoothDeviceBTStateNotifyName;

// 蓝牙设备主动发送各种状态数值的通知名字 | Bluetooth devices actively send notification names for various status values
//object -》IDOControlDataUpdateModel
extern NSString * _Nonnull IDOBluetoothControlDataUpdateNotifyName;

// 文件传输状态通知
extern NSString * _Nonnull IDOBluetoothFileTransferStateNotifyName;

// 单次拍照
extern NSString * _Nonnull IDOBluetootPhotoSingleShotNotifyName;

// 打开APP相机，进入拍照预览功能
extern NSString * _Nonnull IDOBluetootPhotoIntoPreviewNotifyName;

//暂停拍照预览，停止传输照片流
extern NSString * _Nonnull IDOBluetootPhotoStopPreviewNotifyName;

//关闭APP相机，退出拍照预览功能
extern NSString * _Nonnull IDOBluetootPhotoOutPreviewNotifyName;

//通知APP 删除设备
extern NSString * _Nonnull IDOBluetoothDeleteDeviceNotifyName;
//提示APP 重复绑定
extern NSString * _Nonnull IDOBluetoothRepeatBindingNotifyName;

//特征值有0AF8 设备未配对 开始蓝牙配对
extern NSString * _Nonnull IDOBluetoothStartPairNotifyName;

@interface IDOBluetoothServices : NSObject

/*
 是否输出蓝牙sdk运行日志 | Whether to output the Bluetooth sdk running log
 */
@property (nonatomic,copy,nullable) IDOBluetoothServices *_Nonnull(^outputSdkLog)(BOOL isOutput);

/*
 是否输出蓝牙协议运行日志 | Whether to output the Bluetooth protocol running log
 */
@property (nonatomic,copy,nullable) IDOBluetoothServices *_Nonnull(^outputProtocolLog)(BOOL isOutput,BOOL isRecord);

/*
 是否记录原始数据日志 | Whether to log raw data
 */
@property (nonatomic,copy,nullable) IDOBluetoothServices *_Nonnull(^rawDataLog)(BOOL isRecord);

/*
 是否使用功能表判断 | Whether to use function table judge
 */
@property (nonatomic,copy,nullable) IDOBluetoothServices *_Nonnull(^useFunctionTable)(BOOL isUse);

/*
 开始启动需要连接的设备 | Start the device that needs to be connected
 */
@property (nonatomic,copy,nullable) IDOBluetoothServices *_Nonnull(^startConnectDevice)(NSString * _Nullable macAddr);

/**
 * 注册SDK服务后,初始化设备信息并返回,需开始启动蓝牙,根据各自业务需求,可以选择自己的APP创建蓝牙管理,也可以使用我们提供的库创建蓝牙管理.
 * After the SDK service is registered, the device information is initialized and returned, and bluetooth needs to be started.
 * According to their business needs, they can choose their own APP to create bluetooth management, or they can use the library we provide to create bluetooth management.
 */
@property (nonatomic,copy,nullable) void(^startScanBule)(void(^ _Nullable getDeviceInfoBlock)(IDOGetDeviceInfoBluetoothModel * _Nullable model));

/**
 * @brief  注册SDK服务,初始化设备信息 | Register for SDK service,initializes device info
 * password 数据库密码 ｜ Database password
 * macAddr 需要连接的设备 
 * @return IDOBluetoothServices
 */
IDOBluetoothServices * _Nonnull registrationServices(NSString * _Nullable password);

@end
