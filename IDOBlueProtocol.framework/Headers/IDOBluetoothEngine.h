//
//  IDOBluetoothEngine.h
//  VeryfitSDK
//
//  Created by hedongyang on 2018/5/31.
//  Copyright © 2018年 hedongyang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#if __has_include(<IDOBlueProtocol/IDOBlueProtocol.h>)
#else
#import "IDOGetInfoBluetoothModel.h"
#endif

@interface IDOBluetoothManagerInfoEngine : NSObject

/**
 * 蓝牙管理中心 | Bluetooth Management Center
 */
@property (nonatomic,strong) CBCentralManager * centralManager;

/**
 * 外围设备 | Peripherals
 */
@property (nonatomic,strong) CBPeripheral  * peripheral;

/**
 * 蓝牙是否开启权限 | Is authorized?
 */
@property (nonatomic,assign,readonly,getter=isAuthorized) BOOL authorized;

/**
 * 蓝牙是否开启 | Is Bluetooth enabled?
 */
@property (nonatomic,assign,readonly,getter=isPoweredOn) BOOL poweredOn;

/**
 * 蓝牙是否连接 | Bluetooth is connected
 */
@property (nonatomic,assign,readonly,getter=isConnected) BOOL connected;

/**
 * 蓝牙是否正在连接中 | Bluetooth is connecting
 */
@property (nonatomic,assign,readonly,getter=isConnecting) BOOL connecting;

/**
 * 蓝牙是否正在扫描中 | Bluetooth is scanning
 */
@property (nonatomic,assign,readonly,getter=isScanning) BOOL scanning;

/**
 * 命令服务特征 | Command Service Features
 */
@property (nonatomic,strong) CBCharacteristic * commandCharacteristic;

/**
 * 健康服务特征 | Health Service Features
 */
@property (nonatomic,strong) CBCharacteristic * healthCharacteristic;

/**
 * 锐捷定制发送服务特征 | Ruijie write service Features
 */
@property (nonatomic,strong) CBCharacteristic * customWriteCharacteristic;

/**
 * alipay auth 命令服务特征 | alipay auth Command Service Features
 */
@property (nonatomic,strong) CBCharacteristic * alipayAuthCharacteristic;

/**
 * nordic OTA 命令服务特征 | nordic OTA Command Service Features
 */
@property (nonatomic,strong) CBCharacteristic * smsCharacteristic;
/**
 * 功能列表 | Function List
 */
@property (nonatomic,strong) IDOGetDeviceFuncBluetoothModel * funcTableModel;

/**
 软硬件版本信息
 */
@property (nonatomic,strong) IDOGetVersionInfoBluetoothModel * versionModel;

- (void)resetConnect;

@end

@interface IDOBluetoothPeripheralInfoEngine : NSObject

/**
 * 当前连接外围设备的uuid | uuid currently connected to peripherals
 */
@property (nonatomic,copy)   NSString * uuidStr;

/**
 * 当前连接设备ID | Current connection device ID
 */
@property (nonatomic,copy)   NSString * deviceId;

/**
 * 当前连接设备名字 | Current connected device name
 */
@property (nonatomic,copy)   NSString * deviceName;

/**
 * 当前连接设备固件版本号 | Current connected device firmware version number
 */
@property (nonatomic,copy)   NSString * version;

/**
 * 当前连接设备Mac地址  | Currently connected device Mac address
 */
@property (nonatomic,copy)   NSString * macAddr;

/**
 * 当前连接设备授权码 | Currently connected device authorization code
 */
@property (nonatomic,copy)   NSString * authCode;

/**
 * 当前设备连接成功的时间 | The time the current device was successfully connected
 */
@property (nonatomic,strong) NSDate * connectedDate;

/**
 * 当前连接设备模式 | Current connected device mode
 */
@property (nonatomic,assign) NSInteger  deviceMode;

/**
 * 当前连接设备状态 | Current connected device status
 */
@property (nonatomic,assign) NSInteger  battStatus;

/**
 * 当前连接设备电量 | Current connected device power
 */
@property (nonatomic,assign) NSInteger  battLevel;

/**
 * 当前连接设备是否重启 | Is the current connected device restarted?
 */
@property (nonatomic,assign) NSInteger  rebootFlag;

/**
 * 当前连接设备授权码长度 | Current connection device authorization code length
 */
@property (nonatomic,assign) NSInteger  authLength;

/**
 * 当前设备绑定的时间戳 | Current connection device binding timestamp
 */
@property (nonatomic,assign) NSInteger  bindTime;

/**
 * 手环的平台 | platform for bracelet
 * 0:nordic,10:realtek 8762x ,20:cypress psoc6,30:Apollo3,40:汇顶,50:nordic+泰凌微,60:泰凌微+5340+no nand flash,70:汇顶+富瑞坤;80:5340 ,98,99均为思澈(sifli)，112：炬芯
 */
@property (nonatomic,assign) NSInteger platform;

/**
 * 当前连接设备是否绑定 | Is the current connected device bound?
 */
@property (nonatomic,assign) BOOL isBind;

/**
 * 当前连接设备是否配对中 | Is the current connected device pairing?
 */
@property (nonatomic,assign) BOOL isPairing;

/**
 * 当前连接设备是否ota | Is the current connected device ota?
 */
@property (nonatomic,assign) BOOL isOta;

/**
 * 当前连接设备是否泰凌微ota | Is the current connected device tlw ota?
 *  当前在泰凌微ota模式下，优先升级bt文件
 */
@property (nonatomic,assign) BOOL isTlwOta;

/**
 写入蓝牙数据失败 | did write value error
 */
@property (nonatomic,assign) BOOL didWriteValueError;

/**
 发现服务特征完成
 */
@property (nonatomic,assign) BOOL findCharacteristicsEnd;

@end

@interface IDOBluetoothUserInfoEngine : NSObject

/**
 * 用户ID | User ID
 */
@property (nonatomic,copy)   NSString * userId;

/**
 * 用户生日 (例如:2018-10-01) | | User birthday (example: 2018-10-01)
 */
@property (nonatomic,copy)   NSString * birthday;

/**
 * 用户目标步数 | User target steps
 */
@property (nonatomic,assign) NSInteger goalStepCount;

/**
 * 目标睡眠 (分钟) | Target sleep (minutes)
 */
@property (nonatomic,assign) NSInteger goalSleepMinute;

/**
 * 目标卡路里 | Goal Calories
 */
@property (nonatomic,assign) NSInteger goalCalorieData;

/**
 * 目标距离 | Target distance
 */
@property (nonatomic,assign) NSInteger goalDistanceData;

/**
 * 目标体重 (千克) | Target weight (kg)
 */
@property (nonatomic,assign) NSInteger goalWeight;

/**
 * 用户性别 | User gender
 */
@property (nonatomic,assign) NSInteger sex;

/**
 * 用户体重 | User weight
 */
@property (nonatomic,assign) NSInteger weight;

/**
 * 用户升高 | User rises
 */
@property (nonatomic,assign) NSInteger height;

/**
 * 是否登陆 | Login
 */
@property (nonatomic,assign) BOOL isLogin;

@end

@interface IDOBluetoothAppInfoEngine : NSObject

/**
 * 设备名字 | Device Name
 */
@property (nonatomic,copy) NSString * iphoneName;

/**
 * 手机系统版本 | Mobile phone system version
 */
@property (nonatomic,copy) NSString * sysVersion;

/**
 * sdk版本 | sdk version
 */
@property (nonatomic,copy) NSString * sdkVersion;

/**
 * 是否使用功能表判断 | Whether to use function table judge
 */
@property (nonatomic,assign) BOOL isUseFunctionTable;

/**
 * 是否控制台输出日志
 */
@property (nonatomic,assign) BOOL isOutPrintLog;

/**
 是否记录SDK日志
 */
@property (nonatomic,assign) BOOL isRecordLog;
 
@end

@interface IDOBluetoothUnitInfoEngine : NSObject

/**
 * 时间格式是否12小时制 | Is the time format 12-hour format?
 */
@property (nonatomic,assign) BOOL is12Hour;

/**
 * 语言单位 | Language unit
 */
@property (nonatomic,assign) NSInteger language;

/**
 * 距离单位 | Distance unit
 */
@property (nonatomic,assign) NSInteger distUnit;

/**
 * 体重单位 | Weight unit
 */
@property (nonatomic,assign) NSInteger weightUnit;

/**
 * 温度单位 | Temperature unit
 */
@property (nonatomic,assign) NSInteger tempUnit;

/**
 * 走路步伐单位 | Walking pace unit
 */
@property (nonatomic,assign) NSInteger strideWalkUnit;

/**
 * 跑步步伐单位 | Running pace unit
 */
@property (nonatomic,assign) NSInteger strideRunUnit;

@end

@interface IDOBluetoothEngine : NSObject
+ (IDOBluetoothEngine *)shareInstance;
- (void)deserialization;
- (void)getCacheDataWithMacAddr:(NSString *)macAddr;
@property (nonatomic,strong) IDOBluetoothManagerInfoEngine    * managerEngine;
@property (nonatomic,strong) IDOBluetoothPeripheralInfoEngine * peripheralEngine;
@property (nonatomic,strong) IDOBluetoothUserInfoEngine       * userEngine;
@property (nonatomic,strong) IDOBluetoothAppInfoEngine        * appEngine;
@property (nonatomic,strong) IDOBluetoothUnitInfoEngine       * unitEngine;
@end

