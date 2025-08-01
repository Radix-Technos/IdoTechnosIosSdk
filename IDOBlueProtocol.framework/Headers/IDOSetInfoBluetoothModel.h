//
//  IDOSetBuletoothModel.h
//  VeryfitSDK
//
//  Created by hedongyang on 2018/6/13.
//  Copyright © 2018年 hedongyang. All rights reserved.
//

#if __has_include(<IDOBlueProtocol/IDOBlueProtocol.h>)
#else
#import "IDOBluetoothBaseModel.h"
#endif


#pragma mark ==== 情绪健康新数据新模型 ====
@interface IDOV3EmotionPressureReminderConfigModel: IDOBluetoothBaseModel

/**
 压力过高提醒开关 0xAA:开 0x55:关 0x00:无效

 */
@property (nonatomic, assign) NSInteger pressureSwitch;

/**
 提醒开始时间(时)
 */
@property (nonatomic, assign) NSInteger startHour;

/**
 提醒开始时间(分)
 */
@property (nonatomic, assign) NSInteger  startMinute;

/**
 提醒结束时间(时)
 */
@property (nonatomic, assign) NSInteger  endHour;

/**
 提醒结束时间(分)
 */
@property (nonatomic, assign) NSInteger  endMinute;

/**
 重复周期 重复集合 [星期一、星期二、星期三、星期四、星期五、星期六、星期日]
 */
@property (nonatomic, copy) NSArray<NSNumber*>* repeat;

/**
 提醒间隔,单位(分)
 */
@property (nonatomic, assign) NSInteger  reminderInterval;

@end


@interface IDOV3EmotionUnpleasantReminderConfigModel : IDOBluetoothBaseModel

/**
 不愉悦提醒开关 0xAA:开 0x55:关 0x00:无效
 */
@property (nonatomic, assign) NSInteger  unpleasantSwitch;

/**
 不愉悦提醒阈值，0无效
 */
@property (nonatomic, assign) NSInteger  unhappyReminderNum;


@end

@interface IDOV3SetEmotionInfo2Model: IDOBluetoothBaseModel

/**
 版本号
 */
@property (nonatomic, assign) NSInteger eVersion;

/**
 操作类型 0:无效 1:设置 2:查询
 */
@property (nonatomic, assign) NSInteger operate;

/**
 通知类型：0:无效 1:允许通知；2:静默通知；3:关闭通知
 */
@property (nonatomic, assign) NSInteger notifyType;

/**
 情绪健康总开关 0xAA:开 0x55:关 0x00:无效
 */
@property (nonatomic, assign) NSInteger emotionalHealthSwitch;

/**
 压力过高提醒配置
 */
@property (nonatomic, strong) IDOV3EmotionPressureReminderConfigModel* pressureRemind;

/**
 不愉悦提醒配置
 */
@property (nonatomic, strong) IDOV3EmotionUnpleasantReminderConfigModel* unpleasantRemind;

+ (IDOV3SetEmotionInfo2Model *)currentModel;

@end



#pragma mark ==== 情绪健康新数据模型 此模型废弃，协议修改了 ====
@interface IDOV3EmotionPressureReminderItemModel: IDOBluetoothBaseModel

/**
 提醒开始时间(时)
 */
@property (nonatomic, assign) NSInteger startHour;

/**
 提醒开始时间(分)
 */
@property (nonatomic, assign) NSInteger startMinute;

/**
 提醒结束时间(时)
 */
@property (nonatomic, assign) NSInteger endHour;

/**
 提醒结束时间(分)
 */
@property (nonatomic, assign) NSInteger endMinute;


/**
 重复周期 重复集合 [星期一、星期二、星期三、星期四、星期五、星期六、星期日]
 */
@property (nonatomic, copy) NSArray<NSNumber*>* repeat;

/**
 提醒间隔,单位(分)
 */
@property (nonatomic, assign) NSInteger reminderInterval;


@end


@interface IDOV3SetEmotionInfoModel: IDOBluetoothBaseModel

/**
 版本号
 */
@property (nonatomic, assign) NSInteger eVersion;

/**
 操作类型 0:无效 1:设置 2:查询
 */
@property (nonatomic, assign) NSInteger operate;

/**
 通知类型：0:无效 1:允许通知；2:静默通知；3:关闭通知
 */
@property (nonatomic, assign) NSInteger notifyType;

/**
 情绪健康总开关 0xAA:开 0x55:关 0x00:无效
 */
@property (nonatomic, assign) NSInteger emotionalHealthSwitch;

/**
 不愉悦提醒开关 0xAA:开 0x55:关 0x00:无效
 */
@property (nonatomic, assign) NSInteger unpleasantSwitch;


/**
 压力过高提醒开关 0xAA:开 0x55:关 0x00:无效
 */
@property (nonatomic, assign) NSInteger pressureSwitch;

/**
 压力过高提醒项，设置有效
 */
@property (nonatomic, strong) IDOV3EmotionPressureReminderItemModel * pressureItems;

/**
 不愉悦提醒阈值，查询有效
 */
@property (nonatomic, assign) NSInteger  unhappyReminderNum;

+(IDOV3SetEmotionInfoModel *)currentModel;


@end

#pragma mark ==== 女性生理周期日常记录 ====
@interface IDOV3PhysiologicalRecordConfModel: IDOBluetoothBaseModel

/**
 0x01:症状 0x02:点滴出血 0x03:性生活 0x04:心情 0x05:日记
 */
@property (nonatomic, assign) NSInteger dataType;

/**
 支持的数据子项集合：每个bit位代表一个子选项类型,具体参考下表
 */
@property (nonatomic, copy) NSArray<NSNumber *>* dataItems;

@end

@interface IDOV3PhysiologicalRecordDataModel: IDOBluetoothBaseModel

/**
 0x01:症状 0x02:点滴出血 0x03:性生活 0x04:心情 0x05:日记
 */
@property (nonatomic, assign) NSInteger dataType;

/**
 数据项长度
 */
@property (nonatomic, assign) NSInteger itemsLen;


/**
 数据项类型
 无    0x00
 0x01  症状
 0：眩晕
 1：呕吐
 2：失眠
 3：头痛
 4：痤疮
 5：掉发
 6：恶心
 7：记忆力衰退
 8：腹部绞痛
 9：腹泻
10：腹胀
11：盆腔疼痛
12：发冷
13：浮肿
14：皮肤干燥
15：食欲变化
16：乳房疼痛
17：腰酸背痛
18：心情变化
19：夜间盗汗
20：膀胱失禁
21：便秘
22：潮热
比如 @[@(0),@(1),@(2),@(3),@(4),@(5),@(22)]
0x02 点滴出血
0:点滴出血
比如 @[@(0)]
 */
@property (nonatomic, copy) NSArray<NSNumber *>* dataItems;

/**
dataType 0x05：日记 使用此字段
 */
@property (nonatomic, copy) NSString* diaryDataItems;

@end

@interface IDOV3PhysiologicalRecordItemModel: IDOBluetoothBaseModel

/**
 年
 */
@property (nonatomic, assign) NSInteger year;

/**
 月
 */
@property (nonatomic, assign) NSInteger month;

/**
 日
 */
@property (nonatomic, assign) NSInteger day;


@property (nonatomic, assign) NSInteger itemsCount;
 
/**
 数据项
 */
@property (nonatomic, copy) NSArray<IDOV3PhysiologicalRecordDataModel*> *items;

/**
 最后一次修改的时间，操作修改&增加&删除都得更新时间
 */
@property (nonatomic, assign) NSInteger lastChangeTime;

/**
 修改项   0:无效 1:新增 2:修改 3:删除
 */
@property (nonatomic, assign) NSInteger changeType;

@end

@interface IDOV3PhysiologicalRecordModel: IDOBluetoothBaseModel

/**
 版本号
 */
@property (nonatomic, assign) NSInteger pVersion;

/**
 操作类型 0:无效 1:全量设置 2:查询生理日常记录项 3:查询生理日常记录数据 4:修改  5:新增 6:删除 7:获取固件修改项
 */
@property (nonatomic, assign) NSInteger operate;

/**
 最后一次修改的时间，操作修改&增加&删除都得更新时间
 */
@property (nonatomic, assign) NSInteger lastChangeTime;

/**
 总的items的个数,操作1:全量设置,4:修改,5:新增,6:删除时有效
 */
@property (nonatomic, assign) NSInteger allItemsNum;


/**
 已经发送/接收的items的个数,操作1:全量设置,4:修改,5:新增,6:删除时有效
 */
@property (nonatomic, assign) NSInteger finishItemsNum;


/**
 当前包items的个数,操作1:全量设置,4:修改,5:新增,6:删除时有效
 */
@property (nonatomic, assign) NSInteger curItemsNum;

/**
 生理日常记录数据,对应curItemsNum字段数据
 */
@property (nonatomic, copy) NSArray<IDOV3PhysiologicalRecordItemModel*>  *dataItems;

/**
 生理日常记录项个数,操作2:查询生理日常记录项时有效
 */
@property (nonatomic, assign) NSInteger configureItemsNum;

/**
 生理日常记录项,对应configureItemsNum字段数据 操作2:查询生理日常记录项时有效
 */
@property (nonatomic, copy) NSArray<IDOV3PhysiologicalRecordConfModel *>* configureItems;

+(IDOV3PhysiologicalRecordModel *)currentModel;

@end

#pragma mark ==== 情绪健康 model 废弃 ====
@interface IDOV3EmotionReminderFormationItemModel: IDOBluetoothBaseModel

/**
 提醒类型 0:无效 1:不愉悦提醒 2:压力过高提醒
 */
@property (nonatomic, assign) NSInteger type;

/**
 通知类型：0:无效 1:允许通知；2:静默通知；3:关闭通知
 */
@property (nonatomic, assign) NSInteger notifyType;

/**
 提醒开始时间(时)
 */
@property (nonatomic, assign) NSInteger startHour;

/**
 提醒开始时间(分)
 */
@property (nonatomic, assign) NSInteger startMinute;

/**
 提醒结束时间(时)
 */
@property (nonatomic, assign) NSInteger endHour;

/**
 提醒结束时间(分)
 */
@property (nonatomic, assign) NSInteger endMinute;

/**
 重复周期总开关
 */
@property (nonatomic, assign) BOOL isOpen;

/**
 重复周期 重复集合 [星期一、星期二、星期三、星期四、星期五、星期六、星期日]
 */
@property (nonatomic, copy) NSArray<NSNumber*>* repeat;

/**
 提醒间隔,单位(分)
 */
@property (nonatomic, assign) NSInteger reminderInterval;


@end

@interface IDOV3SetEmotionInfomationModel: IDOBluetoothBaseModel

/**
 版本号
 */
@property (nonatomic, assign) NSInteger eVersion;

/**
 操作类型 0:无效 1:设置 2:查询
 */
@property (nonatomic, assign) NSInteger operate;

/**
 情绪健康总开关 YES:开 NO:关
 */
@property (nonatomic, assign) BOOL onOff;

/**
 提醒项个数，最大30个，设置有效
 */
@property (nonatomic, assign) NSInteger itemsNum;

/**
 提醒项，设置有效
 */
@property (nonatomic, copy) NSArray<IDOV3EmotionReminderFormationItemModel *>* items;

/**
 通知类型：0:无效 1:允许通知；2:静默通知；3:关闭通知
 */
@property (nonatomic, assign) NSInteger notifyType;

+(IDOV3SetEmotionInfomationModel *)currentModel;


@end


#pragma mark ==== 小程序设置 model ====

@interface IDOV3SetMiniProgramInfoItemModel : IDOBluetoothBaseModel

/**
 小程序版本号
 */
@property (nonatomic, assign) NSInteger miniProgramVersion;

/**
 小程序版本大小
 */
@property (nonatomic, assign) NSInteger miniProgramSize;

/**
 小程序名称 最大默认30个字节，包含一个结束符
 */
@property (nonatomic, copy) NSString*  miniProgramName;

/**
 小程序1级版本号 (int)((miniProgramVersion >> 24) & 0xFF)
 */
@property (nonatomic, assign) NSInteger miniProgramVersion1;

/**
 小程序2级版本号 (int)((miniProgramVersion >> 16) & 0xFF)
 */
@property (nonatomic, assign) NSInteger miniProgramVersion2;

/**
 小程序3级版本号 (int)((miniProgramVersion >> 8) & 0xFF)
 */
@property (nonatomic, assign) NSInteger miniProgramVersion3;

/**
 小程序4级版本号 (int)(miniProgramVersion & 0xFF)
 */
@property (nonatomic, assign) NSInteger miniProgramVersion4;

@end

@interface IDOV3SetMiniProgramInfoModel : IDOBluetoothBaseModel

/**
 协议版本号
 */
@property (nonatomic, assign) NSInteger pVersion;

/**
 0:无效 1:启动小程序 2:删除小程序 3:获取已安装的小程序列表
 */
@property (nonatomic, assign) NSInteger operate;

/**
 名称 设置有效
 */
@property (nonatomic, copy) NSString* miniProgramName;


/**
 小程序应用列表 获取有效
 */
@property (nonatomic, copy) NSArray<IDOV3SetMiniProgramInfoItemModel *>* items;

/**
 小程序个数 最多50个 获取有效
 */
@property (nonatomic, assign) NSInteger miniProgramNum;

/**
 总空间 获取有效
 */
@property (nonatomic, assign) NSInteger totalSpace;

/**
 剩余空间 获取有效
 */
@property (nonatomic, assign) NSInteger residualSpace;

/**
 支持获取小程序的最大个数，默认是20个 获取有效
 */
@property (nonatomic, assign) NSInteger supportGetMiniProgramMaxNum;

/**
 支持的小程序名称最大长度，默认是30个字节，包含一个结束符 获取有效
 */
@property (nonatomic, assign) NSInteger supportMiniProgramNameMaxLen;

+(IDOV3SetMiniProgramInfoModel *)currentModel;


@end


#pragma mark ==== 设置皮肤温度测量指令model ====
@interface IDOSetTemperatureMeasureInfoModel:IDOBluetoothBaseModel

/**
 * 参数标志 0x01:开始测量皮肤温度， 0x02:结束测量皮肤温度，0x03:获得皮肤温度数据
 * Parameter flags 0x01: start of pressure measurement, 0x02: end of pressure measurement, 0x03: Get pressure data
 */
@property (nonatomic,assign) NSInteger flag;

/**
 * 测量返回状态 0x00:不支持，0x01:正在测量，0x02:测量成功 0x03:测量失败 0x04:设备正在运动模式
 * Return status 0x00: Not supported, 0x01: Positive measurement, 0x02: Measurement success 0x03: Measurement failure 0x04: Device is in motion mode
 */
@property (nonatomic,assign) NSInteger status;

/**
 测量返回皮肤温度数据值 体温实际值*10 比如37.5*10 | Temperature value
 */
@property (nonatomic,assign) NSInteger temperatureValue;

/**
 测量返回皮肤温度数据实际值 体温实际值，保留一位小数 比如 37.5 | Temperature value
 */
@property (nonatomic,copy) NSString* temperatureFloatValue;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetBpMeasureInfoBluetoothModel
 */
+ (IDOSetTemperatureMeasureInfoModel *)currentModel;

@end

#pragma mark ==== 设置一键测量指令model ====
@interface IDOSetOneClickMeasureInfoModel:IDOBluetoothBaseModel

/**
 * 参数标志 0x01:一键测量开始测量，0x02:一键测量结束测量，0x03:获得一键测量数据
 * The parameter flags 0x01: one-click measurement starts the measurement, 0x02: one-click measurement ends the measurement, 0x03: one-click measurement data obtained
 */
@property (nonatomic,assign) NSInteger flag;

/**
 * 测量返回状态码 0x00:不支持，0x01:正在测量，0x02:测量成功 0x03:测量失败 0x04:设备正在运动模式
 * Return status 0x00: Not supported, 0x01: Positive measurement, 0x02: Measurement success 0x03: Measurement failure 0x04: Device is in motion mode
 */
@property (nonatomic,assign) NSInteger status;

/**
 测量返回数据值  心率 | Heart rate value
 */
@property (nonatomic,assign) NSInteger hrValue;

/**
 测量返回数据值  压力 | Stress value
 */
@property (nonatomic,assign) NSInteger stressValue;

/**
 测量返回数据值  血氧 | Spo2 value
 */
@property (nonatomic,assign) NSInteger spo2Value;


/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetBpMeasureInfoBluetoothModel
 */
+ (IDOSetOneClickMeasureInfoModel *)currentModel;

@end


#pragma mark ==== 设置压力测量指令model ====
@interface IDOSetStressMeasureInfoModel:IDOBluetoothBaseModel

/**
 * 参数标志 0x01:开始测量压力， 0x02:结束测量压力，0x03:获得压力数据
 * Parameter flags 0x01: start of pressure measurement, 0x02: end of pressure measurement, 0x03: Get pressure data
 */
@property (nonatomic,assign) NSInteger flag;

/**
 * 测量返回状态 0x00:不支持，0x01:正在测量，0x02:测量成功 0x03:测量失败 0x04:设备正在运动模式
 * Return status 0x00: Not supported, 0x01: Positive measurement, 0x02: Measurement success 0x03: Measurement failure 0x04: Device is in motion mode
 */
@property (nonatomic,assign) NSInteger status;

/**
 测量返回数据值  | Heart rate value
 */
@property (nonatomic,assign) NSInteger value;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetBpMeasureInfoBluetoothModel
 */
+ (IDOSetStressMeasureInfoModel *)currentModel;

@end

#pragma mark ====  游戏设置 model ====
@interface IDOV3SetGameTimeModel: IDOBluetoothBaseModel

/**
 索引
 */
@property (nonatomic, assign) NSInteger index;

/**
 开始时
 */
@property (nonatomic, assign) NSInteger startHour;

/**
 开始分
 */
@property (nonatomic, assign) NSInteger startMinute;

/**
 结束时
 */
@property (nonatomic, assign) NSInteger endHour;

/**
 结束分
 */
@property (nonatomic, assign) NSInteger endMinute;

@end

@interface IDOV3SetGameModel: IDOBluetoothBaseModel

/**
 版本号
 */
@property (nonatomic, assign) NSInteger gameSetVersion;

/**
 操作类型 0:无效 1:设置 2:获取
 */
@property (nonatomic, assign) NSInteger operate;

/**
 总开关
 */
@property (nonatomic, assign) BOOL onOff;


/**
 * 重复集合 [星期一、星期二、星期三、星期四、星期五、星期六、星期日]
 * Repeat collection [monday,tuesday,wednesday,thursday,friday,saturday,sunday]
 */
@property (nonatomic,copy) NSArray<NSNumber *> * repeat;

/**
 状态 0:无效 1:允许 2:禁止
 */
@property (nonatomic, assign) NSInteger status;


/**
 修改信息的UTC时间
 */
@property (nonatomic,assign) NSInteger changeTime;

/**
 游戏显示开关 0无效(不展示) 0x55关  0xAA开  
 */
@property (nonatomic,assign) NSInteger gameShow;

/**
 定时禁止开关 0无效(不展示) 0x55关 0xAA开
 */
@property (nonatomic,assign) NSInteger timeBan;

/**
 用户密码(1-6位) 最长10位
 */
@property (nonatomic,copy) NSString* userPassword;

/**
 时间段个数，最大10个,设置有效
 */
@property (nonatomic,assign) NSUInteger timeNum;

/**
 时间段
 */
@property (nonatomic,copy) NSArray<IDOV3SetGameTimeModel *> * items;

/**
 设备支持设置时间段的最大值,获取有效
 */
@property (nonatomic,assign) NSInteger timeNumMax;

+(IDOV3SetGameModel *)currentModel;

@end

#pragma mark ====  设置V3运动记录显示配置 model ====

@interface IDOV3SportRecordItem:NSObject

/**
  运动记录类型
 */
@property (nonatomic,assign) NSInteger displayItemType;

/**
 具体显示项内容
 */
@property (nonatomic,assign) NSInteger displayItem;

@end

@interface IDOV3SportRecordConfigItem:NSObject

/**
 运动记录类型显示项数组
 */
@property (nonatomic,copy) NSArray<IDOV3SportRecordItem*>* displayItems;

/**
 运动记录类型显示项个数，最大不能超过25
 */
@property (nonatomic,assign) NSInteger displayItemsNum;

/**
 运动类型数组
 */
@property (nonatomic,copy) NSArray<NSNumber*>* sportTypeList;

/**
 运动类型个数，最大5个
 */
@property (nonatomic,assign) NSInteger sportTypeListNum;


@end

@interface IDOV3SportRecordShowConfigDefaultItem: IDOBluetoothBaseModel

/**
 运动记录类型显示项数组
 */
@property (nonatomic,copy) NSArray<IDOV3SportRecordItem*>* displayItems;

/**
 运动记录类型显示项个数，最大不能超过25
 */
@property (nonatomic,assign) NSInteger displayItemsNum;

@end

@interface IDOSetV3SportRecordShowConfigModel:IDOBluetoothBaseModel

/**
 版本号
 */
@property (nonatomic, assign) NSInteger configVersion;
/**
 运动记录显示项个数
 */
@property (nonatomic, assign) NSInteger itemsNum;

/**
 操作  1:增 2:删 3:查 4:改
 */
@property (nonatomic, assign) NSInteger operate;

/**
 支持的操作添加
 */
@property (nonatomic, assign) NSInteger supportOperateAdd;

/**
 支持的操作修改
 */
@property (nonatomic, assign) NSInteger supportOperateChange;

/**
 支持的操作删除
 */
@property (nonatomic, assign) NSInteger supportOperateDelete;

/**
 支持的操作查询
 */
@property (nonatomic, assign) NSInteger supportOperateInquire;


/**
 运动记录显示项内容
 */
@property (nonatomic,copy) NSArray<IDOV3SportRecordConfigItem *>* items;
 
/**
 默认运动记录显示项内容
 */
@property (nonatomic,strong) IDOV3SportRecordShowConfigDefaultItem* defaultItems;

+(IDOSetV3SportRecordShowConfigModel *)currentModel;

@end

#pragma mark ====  设置应用列表壁纸 model ====
@interface IDOSetAppListWallpaperItemModel: IDOBluetoothBaseModel

/**
 应用列表壁纸序号 从0开始
 */
@property (nonatomic,assign) NSInteger index;

/**
 当前应用列表壁纸占用空间 单位byte
 */
@property (nonatomic,assign) NSInteger size;

/**
 字体颜色
 */
@property (nonatomic,copy) NSString *fontColor;

/**
 名字
 */
@property (nonatomic,copy) NSString *wallpaperName;

/**
 壁纸版本号
 */
@property (nonatomic,assign) NSInteger wallpaperVersion;


@end

@interface IDOSetAppListWallpaperResModel: IDOBluetoothBaseModel

@property (nonatomic,assign) NSInteger mVersion;

//操作 1:设置 2:查询 3:删除
@property (nonatomic,assign) NSInteger operate;


//应用列表壁纸的总个数
@property (nonatomic,assign) NSInteger totalNum;

//应用列表壁纸的已经使用个数,最大个数20
@property (nonatomic,assign) NSInteger itemNum;

//应用列表壁纸的总容量，单位Byte
@property (nonatomic,assign) NSInteger totalCapacitySize;

//应用列表壁纸的已经使用容量，单位Byte
@property (nonatomic,assign) NSInteger usedCapacitySize;


//应用列表壁纸数组
@property (nonatomic,copy) NSArray<IDOSetAppListWallpaperItemModel *>* items;

+(IDOSetAppListWallpaperResModel *)currentModel;

@end


@interface IDOSetAppListWallpaperModel: IDOBluetoothBaseModel

/**
 版本号
 */
@property (nonatomic,assign) NSInteger mVersion;

/**
 壁纸版本号
 */
@property (nonatomic,assign) NSInteger wallpaperVersion;

//操作 1:设置 2:查询 3:删除
@property (nonatomic,assign) NSInteger operate;

//字体颜色
@property (nonatomic,copy) NSString *fontColor;

//名字
@property (nonatomic,copy) NSString *wallpaperName;

+(IDOSetAppListWallpaperModel *)currentModel;

@end

#pragma mark ====  设置游戏时间 model ====
@interface IDOSetGameTimeReminder : IDOBluetoothBaseModel
//游戏显示开关
@property (nonatomic,assign) BOOL gameShow;
//定时禁止开关
@property (nonatomic,assign) BOOL timeBan;
//开始 时
@property (nonatomic,assign) NSInteger startHour;
//开始 分
@property (nonatomic,assign) NSInteger startMinute;
//结束 时
@property (nonatomic,assign) NSInteger endHour;
//结束 分
@property (nonatomic,assign) NSInteger endMinute;
/**
 * 重复集合 [星期一、星期二、星期三、星期四、星期五、星期六、星期日]
 * Repeat collection [monday,tuesday,wednesday,thursday,friday,saturday,sunday]
 */
@property (nonatomic,copy)NSArray<NSNumber *> * repeat;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetGameTimeReminder
 */
+ (IDOSetGameTimeReminder *)currentModel;
@end

#pragma mark ====  设置喝水计划 model ====
@interface IDOSetDrinkPlanDataModel : IDOBluetoothBaseModel
//杯子容量1
@property (nonatomic,assign) NSInteger cupCapacity1;
//杯子容量2
@property (nonatomic,assign) NSInteger cupCapacity2;
//喝水目标 单位ml/天
@property (nonatomic,assign) NSInteger drinkTarget;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetDrinkPlanDataModel
 */
+ (IDOSetDrinkPlanDataModel *)currentModel;
@end

#pragma mark ====  设置呼吸率开关 model ====
@interface IDOSetBreathRateSwitchModel : IDOBluetoothBaseModel
/**
 开关状态
 */
@property (nonatomic,assign) BOOL onOff;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetBreathRateSwitchModel
 */
+ (IDOSetBreathRateSwitchModel *)currentModel;

@end
#pragma mark ====  设置身体电量开关 model ====
@interface IDOSetBodyPowerSwitchModel : IDOBluetoothBaseModel
/**
 开关状态
 */
@property (nonatomic,assign) BOOL onOff;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetBreathRateSwitchModel
 */
+ (IDOSetBodyPowerSwitchModel *)currentModel;

@end


#pragma mark ====  设置通知应用状态 model ====
@interface IDOSetNotificationStatusModel : IDOBluetoothBaseModel

/**
 通知类型 ： 0无效 ； 1：允许通知； 2：静默通知； 3：关闭通知
 */
@property (nonatomic,assign) NSInteger notifyFlag;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetNotificationStatusModel
 */
+ (IDOSetNotificationStatusModel *)currentModel;

@end

#pragma mark ====  设置未读APP提醒(应用通知红点提醒) model ====
@interface IDOSetUnReadAppReminderModel : IDOBluetoothBaseModel
//开关
@property (nonatomic,assign) BOOL onOff;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetUnReadAppReminderModel
 */
+ (IDOSetUnReadAppReminderModel *)currentModel;

@end

#pragma mark ====  设置自定义时间走动提醒(定制) model ====

@interface IDOSetCustomTimeWalkReminderModel : IDOBluetoothBaseModel

/**
 开关
 */
@property (nonatomic,assign) BOOL onOff;
/**
 走动提醒数组，最多20个。数组元素为字典，
 包含remindHour\remindMinute,eg:{@"remindHour":@"10",@"remindMinute":@"30"}
 */
@property (nonatomic,copy) NSArray <NSDictionary *>* items;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetCustomTimeWalkReminderModel
 */
+ (IDOSetCustomTimeWalkReminderModel *)currentModel;

@end

#pragma mark ====  设置智能心率模式 model ====
@interface IDOSetSmartHeartRateModel : IDOBluetoothBaseModel
/**
 智能心率模式   yes 为开  no 为关
 */
@property (nonatomic,assign) BOOL modeFlag;
/**
 通知类型 ： 0无效 ； 1：允许通知； 2：静默通知； 3：关闭通知
 */
@property (nonatomic,assign) NSInteger notifyFlag;
/**
 开启智能心率过高提醒开关 yes 为开 no为关
 */
@property (nonatomic,assign)BOOL highHeartMode;
/**
 开启智能心率过低提醒开关  yes 为开 no为关
 */
@property (nonatomic,assign)BOOL lowHeartMode;
/**
 智能心率过高提醒阈值
*/
@property (nonatomic,assign) NSInteger highHeartValue;
/**
智能心率过低提醒阈值
*/
@property (nonatomic,assign) NSInteger lowHeartValue;

/**
 智能心率测量时间间隔
 */
@property (nonatomic,assign) NSInteger measurementInterval;

/**
 心率监测时间段 开始时 获取有效
 */
@property (nonatomic,assign) NSInteger startHour;

/**
 心率监测时间段 开始分 获取有效
 */
@property (nonatomic,assign) NSInteger startMinute;

/**
 心率监测时间段 结束时 获取有效
 */
@property (nonatomic,assign) NSInteger endHour;

/**
 心率监测时间段 结束分 获取有效 
 */
@property (nonatomic,assign) NSInteger endMinute;

/**
 智能心率默认支持测量频率数组 单位s @[@600,@1200,@1800]
 */
@property (nonatomic,copy) NSArray *supportMFArray;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetSmartHeartRateModel
 */
+ (IDOSetSmartHeartRateModel *)currentModel;

@end

#pragma mark ====  设置科学睡眠开关 model ====
@interface IDOSetV3ScientificSleepModel : IDOBluetoothBaseModel

/**
 模式 yes（科学睡眠）,no(普通睡眠)
 */
@property (nonatomic,assign) BOOL mode;
/**
 开始  时
 */
@property (nonatomic,assign) NSInteger startHour;
/**
 开始  分
 */
@property (nonatomic,assign) NSInteger startMinute;
/**
 结束  时
 */
@property (nonatomic,assign) NSInteger endHour;
/**
 结束  分
 */
@property (nonatomic,assign) NSInteger endMinute;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetV3ScientificSleepModel
 */
+ (IDOSetV3ScientificSleepModel *)currentModel;

@end

#pragma mark ====  夜间体温开关 model ====
@interface IDOSetV3TemperatureModel : IDOBluetoothBaseModel
/**
 开关 yes开,no关闭
 */
@property (nonatomic,assign) BOOL mode;
/**
 开始  时
 */
@property (nonatomic,assign) NSInteger startHour;
/**
 开始  分
 */
@property (nonatomic,assign) NSInteger startMinute;
/**
 结束  时
 */
@property (nonatomic,assign) NSInteger endHour;
/**
 结束  分
 */
@property (nonatomic,assign) NSInteger endMinute;
/**
 体温单位设置： 1 ：c（摄氏度）   16 ：f（华摄氏度）
 */
@property (nonatomic,assign) NSInteger unit;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetV3TemperatureModel
 */
+ (IDOSetV3TemperatureModel *)currentModel;

@end

#pragma mark ====  增加环境音量的开关 model ===
@interface IDOSetV3NoiseSwitchModel : IDOBluetoothBaseModel
/**
 开关 yes:开,no关闭
 */
@property (nonatomic,assign) BOOL mode;
/**
 开始  时
 */
@property (nonatomic,assign) NSInteger startHour;
/**
 开始  分
 */
@property (nonatomic,assign) NSInteger startMinute;
/**
 结束  时
 */
@property (nonatomic,assign) NSInteger endHour;
/**
 结束  分
 */
@property (nonatomic,assign) NSInteger endMinute;
/**
 阀值开关 yes:开,no关闭
 */
@property (nonatomic,assign) BOOL highNoiseOnOff;
/**
 阈值
 */
@property (nonatomic,assign) NSInteger highNoiseValue;

/**
 通知类型 0无效 1:允许通知 2:静默通知 3:关闭通知
 */
@property (nonatomic,assign) NSInteger notify;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetV3NoiseSwitchModel
 */
+ (IDOSetV3NoiseSwitchModel *)currentModel;

@end


#pragma mark ====  健身指导开关下发 model ===
@interface IDOSetFitnessGuidanceModel : IDOBluetoothBaseModel
/**
 开关 yes开,no关闭
 */
@property (nonatomic,assign) BOOL mode;
/**
 走动提醒开关 yes开,no关闭
 */
@property (nonatomic,assign) BOOL walkMode;
/**
 开始  时
 */
@property (nonatomic,assign) NSInteger startHour;
/**
 开始  分
 */
@property (nonatomic,assign) NSInteger startMinute;
/**
 结束  时
 */
@property (nonatomic,assign) NSInteger endHour;
/**
 结束  分
 */
@property (nonatomic,assign) NSInteger endMinute;
/**
 通知类型  0无效 ； 1：允许通知； 2：静默通知； 3：关闭通知
 */
@property (nonatomic,assign) NSInteger notifyFlag;
/**
 * 重复集合 [星期一、星期二、星期三、星期四、星期五、星期六、星期日]
 * Repeat collection [monday,tuesday,wednesday,thursday,friday,saturday,sunday]
 */
@property (nonatomic,copy) NSArray<NSNumber *> * repeat;
/**
 目标步数
 */
@property (nonatomic,assign) NSInteger targetSteps;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetFitnessGuidanceModel
 */
+ (IDOSetFitnessGuidanceModel *)currentModel;

@end

#pragma mark ==== 常用联系人的模型 ====
@interface IDOSetContactItemModel:IDOBluetoothBaseModel
/**
 号码
 */
@property (nonatomic,copy) NSString * phone;

/**
 名字
 */
@property (nonatomic,copy) NSString * name;

@end

#pragma mark ==== 同步协议蓝牙通话常用联系人 ====
@interface IDOSetSyncContactModel:IDOBluetoothBaseModel
/**
 版本号    version
 */
@property (nonatomic,assign) NSInteger conVersion;
/**
 操作 0：无效； 1： 设置常用联系人， 2：查询常用联系人
 */
@property (nonatomic,assign) NSInteger operat;
/**
 items的个数
 */
@property (nonatomic,assign) NSInteger itemsNum;
/**
联系人集合 ｜ alarm items
*/
@property (nonatomic,copy) NSArray <IDOSetContactItemModel *>* items;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetSyncContactModel
 */
+ (IDOSetSyncContactModel *)currentModel;

@end

#pragma mark ==== 同步协议蓝牙通话常用联系人 ====
@interface IDOSetSyncEmergencyContactModel:IDOBluetoothBaseModel
/**
 版本号    version
 */
@property (nonatomic,assign) NSInteger conVersion;
/**
 操作 0：无效；  3:设置紧急联系人 4:查询紧急联系人
 （3、4操作需要功能表支持:IDOGetFuncTable29BluetoothModel：supportV3SetEmergencyConnact;//支持设置查询紧急联系人）
 */
@property (nonatomic,assign) NSInteger operat;
/**
 items的个数
 */
@property (nonatomic,assign) NSInteger itemsNum;
/**
联系人集合 ｜ alarm items
*/
@property (nonatomic,copy) NSArray <IDOSetContactItemModel *>* items;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetSyncContactModel
 */
+ (IDOSetSyncEmergencyContactModel *)currentModel;

@end


#pragma mark ==== 设置世界时间 ====
@interface IDOSetV3WorldTimeItemModel:IDOBluetoothBaseModel
/**
 每个城市的id号
 */
@property (nonatomic,assign) NSInteger cityId;
/**
 当前的时间和0时区的偏移分钟数据
 */
@property (nonatomic,assign) NSInteger minuteOffset;
/**
 城市的名称（city_name）长度
 */
@property (nonatomic,assign) NSInteger cityNameLen;
/**
 城市名称
 */
@property (nonatomic,copy) NSString  * cityName;
/**
 日出的时
 */
@property (nonatomic,assign) NSInteger sunriseHour;
/**
 日出的分
 */
@property (nonatomic,assign) NSInteger sunriseMin;
/**
 日落的时
 */
@property (nonatomic,assign) NSInteger sunsetHour;
/**
 日落的分
 */
@property (nonatomic,assign) NSInteger sunsetMin;
/**
 经度标志位   1: 东经； 2：西经
 */
@property (nonatomic,assign) NSInteger longitudeFlag;
/**
 lon=104°4’ => (104 + 4/60)*100 取整
 经度  保留2位小数扩大100倍传输， app需要将对应的分转换成度
 */
@property (nonatomic,assign) NSInteger longitude;
/**
 纬度标志位  1: 北纬； 2：南纬
 */
@property (nonatomic,assign) NSInteger latitudeFlag;
/**
 lat=104°4’ => (104 + 4/60)*100 取整
 纬度  保留2位小数扩大100倍传输， app需要将对应的分转换成度
 */
@property (nonatomic,assign) NSInteger latitude;

@end

@interface IDOSetV3WorldTimeModel:IDOBluetoothBaseModel
/**
 版本号
 */
@property (nonatomic,assign) NSInteger worldVersion;
/**
 items的个数
 */
@property (nonatomic,assign) NSInteger itemsNum;
/**
时钟集合 ｜ time items
*/
@property (nonatomic,copy) NSArray <IDOSetV3WorldTimeItemModel *>* items;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetV3WorldTimeModel
 */
+ (IDOSetV3WorldTimeModel *)currentModel;

@end

#pragma mark ==== 未来7天天气情况 Model ====
@interface IDOFuture7DayWeatherDataModel:IDOBluetoothBaseModel
/**
 天气类型
 */
@property (nonatomic,assign) NSInteger weatherType;
/**
 最大温度 温度值加 100
 */
@property (nonatomic,assign) NSInteger maxTemp;
/**
 最小温度 温度值加 100
 */
@property (nonatomic,assign) NSInteger minTemp;

@end


#pragma mark ==== 未来3天日出日落情况 Model ====
@interface IDOFutureSunriseWeatherDataItems:IDOBluetoothBaseModel
/**
 日出 时钟
 */
@property (nonatomic,assign) NSInteger sunriseHour;
/**
 日出 分钟
 */
@property (nonatomic,assign) NSInteger sunriseMin;
/**
 日落 时钟
 */
@property (nonatomic,assign) NSInteger sunsetHour;
/**
 日落 发钟
 */
@property (nonatomic,assign) NSInteger sunsetMin;

@end

#pragma mark ==== 未来24小时天气情况 Model ====
@interface IDOFuture24HourWeatherModel:IDOBluetoothBaseModel
/**
 天气类型
 */
@property (nonatomic,assign) NSInteger weatherType;
/**
 温度 温度值加 100
 */
@property (nonatomic,assign) NSInteger temperature;
/**
 出现的概率
 */
@property (nonatomic,assign) NSInteger probability;

@end

#pragma mark ==== V3 天气设置 Model ====
@interface IDOSetV3WeatherDataModel:IDOBluetoothBaseModel
/**
 版本号
 */
@property (nonatomic,assign) NSInteger weatherVersion;
/**
 month
 */
@property (nonatomic,assign) NSInteger month;
/**
 day
 */
@property (nonatomic,assign) NSInteger day;
/**
 hour
 */
@property (nonatomic,assign) NSInteger hour;
/**
 min
 */
@property (nonatomic,assign) NSInteger min;
/**
 sec
 */
@property (nonatomic,assign) NSInteger sec;

/**
 week 周日：0、周一：1、周二：2、周三：3、周四：4、周五：5、周六：6
 */
@property (nonatomic,assign) NSInteger week;
/**
 * 天气情况(0:其他， 1:晴， 2:多云， 3:阴，4:雨，5:暴雨，
 * 6:雷阵雨， 7:雪， 8:雨夹雪，9:台风， 10:沙尘暴, 11:夜 间晴，
 * 12:夜间多云， 13:热， 14:冷， 15:清风， 16:大风， 17:雾霭，18:阵雨, 19:多云转晴
 * 20: 新月 , 21: 峨眉月 , 22: 上弦月 23: 盈凸月 24: 满月 25: 亏凸月 , 26: 下弦月 27: 残月
 * 48:雷 , 49:冰雹 , 50:扬沙 , 51:龙卷风)
 * weather conditions (0: others, 1: sunny, 2: cloudy, 3: cloudy, 4: rain, 5: rainstorm,
 * 6: thunderstorm, 7: snow, 8: sleet, 9: typhoon, 10: sandstorm, 11: night clear,
 * 12: cloudy night, 13: hot, 14: cold, 15: breezy, 16: blustery, 17: mist, 18: showers, 19: cloudy to clear)
 */
@property (nonatomic,assign) NSInteger weatherType;
/**
 当前的温度 温度值加 100
 */
@property (nonatomic,assign) NSInteger todayTmp;
/**
 最大温度 温度值加 100
 */
@property (nonatomic,assign) NSInteger todayMaxTemp;
/**
 最少温度 温度值加 100
 */
@property (nonatomic,assign) NSInteger todayMinTemp;
/**
 城市长度
 */
@property (nonatomic,assign) NSInteger cityNameLen;
/**
 城市名称
 */
@property (nonatomic,copy) NSString * cityName;
/**
 空气质量
 */
@property (nonatomic,assign) NSInteger airQuality;
/**
 降水概率
 */
@property (nonatomic,assign) NSInteger precipitationProbability;
/**
 湿度
 */
@property (nonatomic,assign) NSInteger humidity;
/**
 紫外线强度
 */
@property (nonatomic,assign) NSInteger todayUvIntensity;
/**
 风速
 */
@property (nonatomic,assign) NSInteger windSpeed;
/**
 风力
 */
@property (nonatomic,assign) NSInteger windForce;
/**
 日出 时钟
 */
@property (nonatomic,assign) NSInteger sunriseHour;
/**
 日出 分钟
 */
@property (nonatomic,assign) NSInteger sunriseMin;
/**
 日落 时钟
 */
@property (nonatomic,assign) NSInteger sunsetHour;
/**
 日落 发钟
 */
@property (nonatomic,assign) NSInteger sunsetMin;
/**
 空气质量描述
 */
@property (nonatomic,copy) NSString * airGradeInfo;
/**
未来24小时天气集合(扩展可下发48小时天气) ｜  items
*/
@property (nonatomic,copy) NSArray <IDOFuture24HourWeatherModel *>* future24HoursItems;
/**
 未来7天气集合 ｜  items
*/
@property (nonatomic,copy) NSArray <IDOFuture7DayWeatherDataModel *>* future7DaysItems;
/**
 未来3日落日出天气集合 ｜3Days  items（V3 Sunrise）
*/
@property (nonatomic,copy) NSArray <IDOFutureSunriseWeatherDataItems *>* futureSunriseItems;
/**
 积雪厚度 0~100 单位：cm （snowDepth废弃：使用snowDepthMin和snowDepthMax代替）
 需要功能表支持：IDOGetFuncTable31BluetoothModel->v3WeatcherAddSnowDepth
 */
@property (nonatomic,assign) NSInteger snowDepth DEPRECATED_MSG_ATTRIBUTE("this attribute is discarded");

/**
 最小积雪厚度 0~100 单位：cm
 需要功能表支持：IDOGetFuncTable31BluetoothModel->v3WeatcherAddSnowDepth
 */
@property (nonatomic,assign) NSInteger snowDepthMin;

/**
 最大积雪厚度 0~100 单位：cm
 需要功能表支持：IDOGetFuncTable31BluetoothModel->v3WeatcherAddSnowDepth
 */
@property (nonatomic,assign) NSInteger snowDepthMax;

/**
 降雪量 0~100 单位：mm
 需要功能表支持：IDOGetFuncTable31BluetoothModel->v3WeatcherAddSnowfall
 */
@property (nonatomic,assign) NSInteger snowfall;
/**
 大气压强 30000~110000 单位：帕
 需要功能表支持：IDOGetFuncTable31BluetoothModel->v3WeatcherAddAtmosphericpressure
 */
@property (nonatomic,assign) NSInteger atmosphericPressure;


// 需要功能表支持：__IDO_FUNCTABLE__.funcTable31Model.v3WeatcherSendStructVersion04

/**
 月相
 0x0：无效 0x1：新月(N)  0x2：蛾眉月(WXC)  0x3：上弦月(FQ)
 0x4：盈凸月（WXG） 0x5：满月(F)  0x6：亏凸月(WNG)   0x7：下弦月(LQ)
 0x8：残月(WNC)）
 */
@property (nonatomic,assign) NSInteger moonPhase;
/**
 月出：时
 */
@property (nonatomic,assign) NSInteger moonriseHour;
/**
 月出：分
 */
@property (nonatomic,assign) NSInteger moonriseMin;
/**
 月落：时
 */
@property (nonatomic,assign) NSInteger moonsetHour;
/**
 月落：分
 */
@property (nonatomic,assign) NSInteger moonsetMin;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetV3WeatherDataModel
 */
+ (IDOSetV3WeatherDataModel *)currentModel;

@end

#pragma mark ====  设置第三方应用的通知状态 item  model ====
@interface IDOSetAppNotifyStateItemModel : IDOBluetoothBaseModel
/**
 事件类型
*/
@property (nonatomic,assign) NSInteger evtType;
/**
 通知状态  允许通知：1，静默通知 ：2， 关闭通知：3
 | Notification Status Allow Notification: 1, Silent Notification: 2, Turn Off Notification: 3
 */
@property (nonatomic,assign) NSInteger notifyState;
/**
 0x00:无效； 1：有下载对应的图片；2：没有对应的图片  (设置通知状态，此属性忽略)
 */
@property (nonatomic,assign) NSInteger picFlag;
/**
 应用包名 (设置通知状态，此属性忽略)
 */
@property (nonatomic,copy) NSString * packName;
/**
 应用名称  (设置通知状态，此属性忽略)
 */
@property (nonatomic,copy) NSString * appName;

@end

#pragma mark ====  设置第三方应用的通知状态  model ====
@interface IDOSetV3NotifyStateModel : IDOBluetoothBaseModel
/**
 版本
 */
@property (nonatomic,assign) NSInteger msgVersion;
/**
 增删改  1：增加； 2：修改;  3:获取查询
 */
@property (nonatomic,assign) NSInteger operat;
/**
 发送的总包数
 */
@property (nonatomic,assign) NSInteger allSendNum;
/**
 当前发送的序列 
 */
@property (nonatomic,assign) NSInteger nowSendIndex;
/**
 集合个数
 */
@property (nonatomic,assign) NSInteger itemsNum;
/**
 所有消息通知开关
 */
@property (nonatomic,assign) BOOL allOnOff;
/**
 通知状态总开关 0:无效 1:全部允许通知 2:全部静默通知 3:全部关闭通知  仅增加/修改有效
 */
@property (nonatomic,assign) NSInteger allNotifyState;
/**
 通知状态集合 ｜  items
*/
@property (nonatomic,copy) NSArray <IDOSetAppNotifyStateItemModel *>* items;


/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetV3NotifyStateModel
 */
+ (IDOSetV3NotifyStateModel *)currentModel;

@end

#pragma mark ====  设置运动子项数据排列  model ====
@interface IDOSetSportParameterSortModel : IDOBluetoothBaseModel
/**
 * 版本
 */
@property (nonatomic,assign) NSInteger paraVersion;
/**
 *  操作 0:无效； 1查询； 2设置
 */
@property (nonatomic,assign) NSInteger operate;
/**
 * 运动类型
 * 具体参考IDO_SPORT_PAR_TYPE类型
 */
@property (nonatomic,assign) IDO_SPORT_PAR_TYPE sportType;
/**
 * 已经添加的运动索引
 */
@property (nonatomic,assign) NSInteger currentIndex;
/**
 * 个数
 */
@property (nonatomic,assign) NSInteger allNum;
/**
 * 0无效 1运动时长 2距离 3卡路里 4实时心率 + 心率区间
 * 5实时配速 6实时步频 7有氧训练效果 8滚动配速 9平均配速
 * 10步数 11趟数 12最近泳姿 13最近一趟SWOLF 14步数
 * 15踏频 16有氧训练效果 17浆次 18浆频 19时间
 */
@property (nonatomic,copy) NSArray<NSNumber *> * items;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetSportParamSortModel
 */
+ (IDOSetSportParameterSortModel *)currentModel;

@end

#pragma mark ====  设置日程提醒 model ====
@interface IDOSetRemindItemModel : IDOBluetoothBaseModel
/**
 日程提醒id
 */
@property (nonatomic,assign) NSInteger remindId;
/**
 年份
 */
@property (nonatomic,assign) NSInteger year;
/**
 月份
 */
@property (nonatomic,assign) NSInteger month;
/**
 日期
 */
@property (nonatomic,assign) NSInteger day;
/**
 时
 */
@property (nonatomic,assign) NSInteger hour;
/**
 分
 */
@property (nonatomic,assign) NSInteger minute;
/**
 秒
 */
@property (nonatomic,assign) NSInteger second;


/**
 * 若支持功能表 __IDO_FUNCTABLE__.funcTable28Model.supportV3RepeatWeekTypeSeting，
 * 则 repeat表示的是 -> 重复集合 [星期一、星期二、星期三、星期四、星期五、星期六、星期日]
 * Repeat collection [monday,tuesday,wednesday,thursday,friday,saturday,sunday]
 * example ---》[@(1),@(1),@(0),@(0),@(0),@(0),@(0)]
 * Indicates that repeated reminders will be turned on on Monday and Tuesday, and will be turned off at other times
 * ps:  repeatDateValue 和 repeat 只会同时只支持一种
 */
@property (nonatomic,copy) NSArray<NSNumber *> * repeat;

/**
 * 若支持功能表 __IDO_FUNCTABLE__.funcTable29Model.supportV3RepScheduleReminder，
 * 则 repeatValue表示的是 -> (0:无效 1:仅一次 2:每天 3:每周 4:每月 5:每年）
 * Then repeat represents ->(0: invalid 1: only once 2: daily 3: weekly 4: monthly 5: annually)
 * ps:  repeatDateValue 和 repeat 只会同时只支持一种
 */
@property (nonatomic,assign) NSInteger repeatDateValue;

/**
 * 提醒类型 0:不提醒 2:准时 4:提前5分钟 8:提前10分钟 16:提前30分钟 32:提前1小时 64:提前1天
 */
@property (nonatomic,assign) NSInteger nowDayRemindType DEPRECATED_MSG_ATTRIBUTE("this attribute is discarded");
/**
 * 超过天数提醒类型 0:当天 2:提前1天 4:提前2天 8:提前3天 16:提前1周
 */
@property (nonatomic,assign) NSInteger futureRemindType DEPRECATED_MSG_ATTRIBUTE("this attribute is discarded");
/**
 当天提醒开关 0是关,1是开
 */
@property (nonatomic,assign) BOOL remindOnOff;
/**
 * 状态码 0:无效, 1：删除状态, 2：启用状态
 */
@property (nonatomic,assign) NSInteger state;
/**
 标题
 */
@property (nonatomic,strong) NSString *title;
/**
 提示
 */
@property (nonatomic,strong) NSString *note;

@end

@interface IDOSetV3ScheduleReminderModel : IDOBluetoothBaseModel
/**
 * 版本号
 */
@property (nonatomic,assign) NSInteger scVersion;
/**
 * 操作类型 0:无效,1:增, 2:删, 3:查,4:改
 */
@property (nonatomic,assign) NSInteger operate;
/**
 * items的个数 设置 1:增, 2:删,4:改 num传1，3:查 num传0
 */
@property (nonatomic,assign) NSInteger num;
/**
 * 最大设置5个数据过去 设置的时候填充对应的数据结构体
 */
@property (nonatomic,copy) NSArray<IDOSetRemindItemModel *> * items;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetV3ScheduleReminderModel
 */
+ (IDOSetV3ScheduleReminderModel *)currentModel;

@end

#pragma mark ====  设置主界面控件的排序 model ====
@interface IDOMainInterfaceItemModel : IDOBluetoothBaseModel
/**
 * 横轴x 从1开始
 */
@property (nonatomic,assign) NSInteger locationX;
/**
 * 纵轴y 从1开始
 */
@property (nonatomic,assign) NSInteger locationY;
/**
 * 0无效；1：大图标(一个占用一个大的横格)； 2：小图标（2个占用一个横格）
 */
@property (nonatomic,assign) NSInteger sizeType;
/**
 固件支持可以编辑的图标类型 0 ： 无效； 1：大图标； 2：小图标；3:大图标+小图标；
 */
@property (nonatomic,assign) NSInteger supportSizeType;
/**
 * 0无效1活动三环 （小图标）2步数 3最近一次活动 4音乐 5天气 6心率 7压力 8睡眠
 * 9Alexa 10体温 11血氧 12计时器 13闹钟 14事项提醒（现日程提醒）
 * 15噪声 16电量 17电话（联系人）18世界时间
 */
@property (nonatomic,assign) NSInteger widgetsType;

@end

@interface IDOMainInterfaceSupportItemModel : IDOBluetoothBaseModel
/**
 固件支持可以编辑的图标类型 0 ： 无效； 1：大图标； 2：小图标；3:大图标+小图标
 */
@property (nonatomic,assign) NSInteger supportSizeType;
/**
 * 0无效1活动三环 （小图标）2步数 3最近一次活动 4音乐 5天气 6心率 7压力 8睡眠
 * 9Alexa 10体温 11血氧 12计时器 13闹钟 14事项提醒（现日程提醒）
 * 15噪声 16电量 17电话（联系人）18世界时间
 */
@property (nonatomic,assign) NSInteger widgetsType;

@end

@interface IDOMainInterfaceSortModel : IDOBluetoothBaseModel
/**
 * 版本号
 */
@property (nonatomic,assign) NSInteger mainUiVersion;
/**
 * 0：无效； 1查询； 2设置
 */
@property (nonatomic,assign) NSInteger operate;
/**
 * 当前固件组件类型个数
 */
@property (nonatomic,assign) NSInteger allNum;
/**
 * 固件支持所有小组件的类型
 */
@property (nonatomic,assign) NSInteger allSupportNum;
/**
 * 主界面集合
 */
@property (nonatomic,copy) NSArray<IDOMainInterfaceItemModel *> * items;
/**
 * 固件支持可以编辑的图标集合
 */
@property (nonatomic,copy) NSArray<IDOMainInterfaceSupportItemModel *> * supportItems;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOMainInterfaceSortModel
 */
+ (IDOMainInterfaceSortModel *)currentModel;

@end

#pragma mark ====  设置天气日出日落的时间 model ====
@interface IDOSetWeatherSunTimeModel : IDOBluetoothBaseModel
/**
 日出 时钟
 */
@property (nonatomic,assign) NSInteger sunriseHour;
/**
 日出 分钟
 */
@property (nonatomic,assign) NSInteger sunriseMinute;
/**
 日落 时钟
 */
@property (nonatomic,assign) NSInteger sunsetHour;
/**
 日落 分钟
 */
@property (nonatomic,assign) NSInteger sunsetMinute;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetWeatherSunTimeModel
 */
+ (IDOSetWeatherSunTimeModel *)currentModel;

@end

#pragma mark ====  设置洗手提醒 model ====
@interface IDOSetWashHandReminderModel:IDOBluetoothBaseModel
/**
 开关 | on off
 */
@property (nonatomic,assign) BOOL onOff;

/**
 开始时间 （时） | start hour
 */
@property (nonatomic,assign) NSInteger startHour;

/**
 开始时间 （分） | start minute
 */
@property (nonatomic,assign) NSInteger startMinute;

/**
 结束时间 （时） | end hour
 */
@property (nonatomic,assign) NSInteger endHour;

/**
 结束时间 （分） | end minute
 */
@property (nonatomic,assign) NSInteger endMinute;

/**
 * 重复集合 [星期一、星期二、星期三、星期四、星期五、星期六、星期日]
 * Repeat collection [monday,tuesday,wednesday,thursday,friday,saturday,sunday]
 */
@property (nonatomic,strong)NSArray<NSNumber *> * repeat;

/**
 提醒间隔,单位分钟 默认60分钟 | interval (unit minutes)
 */
@property (nonatomic,assign) NSInteger interval;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetWashHandReminderModel
 */
+ (IDOSetWashHandReminderModel *)currentModel;

@end

#pragma mark ====  设置吃药提醒 model ====
@interface IDOSetTakingMedicineReminderItemModel : IDOBluetoothBaseModel
/**
 提醒吃药ID  最多 5个 从1开始 | taking medicine id at most five
 */
@property (nonatomic,assign) NSInteger medicineId;
/**
 开关 | on off
 */
@property (nonatomic,assign) BOOL onOff;

/**
 是否删除 ｜ is delete
 */
@property (nonatomic,assign) BOOL isDelete DEPRECATED_MSG_ATTRIBUTE("this attribute is discarded");

/**
 开始时间 （时） | start hour
 */
@property (nonatomic,assign) NSInteger startHour;

/**
 开始时间 （分） | start minute
 */
@property (nonatomic,assign) NSInteger startMinute;

/**
 结束时间 （时） | end hour
 */
@property (nonatomic,assign) NSInteger endHour;

/**
 结束时间 （分） | end minute
 */
@property (nonatomic,assign) NSInteger endMinute;

/**
 * 重复集合 [星期一、星期二、星期三、星期四、星期五、星期六、星期日]
 * Repeat collection [monday,tuesday,wednesday,thursday,friday,saturday,sunday]
 */
@property (nonatomic,copy)NSArray<NSNumber *> * repeat;

/**
 提醒间隔 单位分钟，默认60分钟 ｜ interval
 */
@property (nonatomic,assign) NSInteger interval;

/*
勿扰开关 | do not distrub on off
*/
@property (nonatomic,assign) BOOL doNotDistrubOnOff;

/*
勿扰开始时 | do not distrub start hour
*/
@property (nonatomic,assign) NSInteger doNotDistrubStartHour;

/*
勿扰开始分 | do not distrub start minute
*/
@property (nonatomic,assign) NSInteger doNotDistrubStartMinute;

/*
勿扰结束时 | do not distrub end hour
*/
@property (nonatomic,assign) NSInteger doNotDistrubEndHour;

/*
勿扰结束分 | do not distrub end minute
*/
@property (nonatomic,assign) NSInteger doNotDistrubEndMinute;

@end

@interface IDOSetTakingMedicineReminderModel : IDOBluetoothBaseModel
/*
提醒个数 最多5个 | reminder count at most five
*/
@property (nonatomic,assign) NSInteger itemCount;
/**
 吃药提醒集合 ｜ taking medicine reminder array
 */
@property (nonatomic,copy) NSArray<IDOSetTakingMedicineReminderItemModel *> * items;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetTakingMedicineReminderModel
 */
+ (IDOSetTakingMedicineReminderModel *)currentModel;

@end

#pragma mark ====  设置压力开关控制 model ====
@interface IDOSetPressureSwitchBluetoothModel:IDOBluetoothBaseModel
/**
 开关 | on off
 */
@property (nonatomic,assign) BOOL onOff;

/**
 开始时间 （时） | start hour
 */
@property (nonatomic,assign) NSInteger startHour;

/**
 开始时间 （分） | start minute
 */
@property (nonatomic,assign) NSInteger startMinute;

/**
 结束时间 （时） | end hour
 */
@property (nonatomic,assign) NSInteger endHour;

/**
 结束时间 （分） | end minute
 */
@property (nonatomic,assign) NSInteger endMinute;

/**
 压力提醒 开关  | remind on off
 */
@property (nonatomic,assign) BOOL remindOnOff;

/**
 * 重复集合 [星期一、星期二、星期三、星期四、星期五、星期六、星期日]
 * Repeat collection [monday,tuesday,wednesday,thursday,friday,saturday,sunday]
 */
@property (nonatomic,copy)NSArray<NSNumber *> * repeat;

/**
 提醒间隔,单位分钟 默认60分钟 | interval (unit minutes)
 */
@property (nonatomic,assign) NSInteger interval;
/**
 压力过高阈值 | High pressure threshold
 */
@property (nonatomic,assign) NSInteger highThreshold;
/**
 通知类型 ： 0无效 ； 1：允许通知； 2：静默通知； 3：关闭通知
 __IDO_FUNCTABLE__.funcTable35Model.pressureNotifyFlagMode
 */
@property (nonatomic,assign) NSInteger notifyFlag;
/**
 压力校准阀值
 */
@property (nonatomic,assign) NSInteger stressThreshold;

/**
 压力测量间隔 单位分钟 IDR01项目增加app设置测量间隔
 */
@property (nonatomic,assign) NSInteger measurementInterval;

/**
 压力默认支持的测量频率数组 单位分钟 @[@10,@20,@30]
 */
@property (nonatomic,copy) NSArray *supportMFArray;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetPressureSwitchBluetoothModel
 */
+ (IDOSetPressureSwitchBluetoothModel *)currentModel;

@end

#pragma mark ====  设置喝水提醒 model ====
@interface IDOSetDrinkReminderModeBluetoothModel:IDOBluetoothBaseModel
/**
 喝水提醒开关 | drink water reminder
 */
@property (nonatomic,assign) BOOL onOff;
/**
 提醒间隔,单位分钟 | interval (unit minutes)
 */
@property (nonatomic,assign) NSInteger interval;
/**
 开始时间（时） | start time (hours)
 */
@property (nonatomic,assign) NSInteger startHour;
/**
 开始时间（分） | start time (minutes)
 */
@property (nonatomic,assign) NSInteger startMinute;
/**
 结束时间 （时） | end time (hours)
 */
@property (nonatomic,assign) NSInteger endHour;
/**
 结束时间 （分） | end time (minutes)
 */
@property (nonatomic,assign) NSInteger endMinute;
/**
 * 重复集合 [星期一、星期二、星期三、星期四、星期五、星期六、星期日]
 * Repeat collection [monday,tuesday,wednesday,thursday,friday,saturday,sunday]
 * Repeat collection [@(0),@(0),,@(0),@(0),,@(0),,@(0),,@(0),]
 */
@property (nonatomic,copy)NSArray<NSNumber *> * repeat;
/**
 通知类型 0无效 ； 1：允许通知； 2：静默通知； 3：关闭通知
 __IDO_FUNCTABLE__.funcTable35Model.drinkWaterNotifyFlag
 */
@property (nonatomic,assign) NSInteger notifyFlag;


/** 支持走动提醒设置/获取免提醒时间段
 __IDO_FUNCTABLE__.funcTable29Model.supportSetWalkNoReminder
 */
/**
 支持走动提醒设置/获取免提醒时间段 | doNotDisturbOnOff
 */
@property (nonatomic,assign) BOOL doNotDisturbOnOff;
/**
 开始时间 （时） | start time (hour)
 */
@property (nonatomic,assign) NSInteger noDisturbStartHour;
/**
 开始时间 （分） | start time (minutes)
 */
@property (nonatomic,assign) NSInteger noDisturbStartMinute;
/**
 结束时间 （时） | end time (hour)
 */
@property (nonatomic,assign) NSInteger noDisturbEndHour;
/**
 结束时间 （分） | end time (minutes)
 */
@property (nonatomic,assign) NSInteger noDisturbEndMinute;


/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetDrinkReminderModeBluetoothModel
 */
+ (IDOSetDrinkReminderModeBluetoothModel *)currentModel;
@end

#pragma mark ====  设置心率开关同步 model ====
@interface IDOSetV3HeartRateModeBluetoothModel:IDOBluetoothBaseModel
/**
 * 心率模式 0:关闭心率监测功能(无效) 1:手动模式(关闭自动) 2:自动模式(5分钟) 3:持续监测(5秒钟)（默认：自动模式）
 * 4:默认类型(第一次绑定同步配置使用) 5:设置对应测量间隔（设置对应的measurement_interval）,选择4和5模式则2和3模式无效 6:智能心率模式 （206沃尔定制）
 * Heart Rate Mode 0: turn off heart rate monitoring function 1: manual mode 2: auto mode 3:continuously monitor(Default: Auto mode)
 * 4: default type (used for the first binding synchronization configuration) 5: set the corresponding measurement interval（set the measurementInterval interval to have an effect）
 */
@property (nonatomic,assign) NSInteger modeType;

/**
 * 更新时间unix 时间戳,秒级  (eg 14442361933)
 * //更新时间unix 时间戳,秒级 等于0是获取，当前的utc时间挫是设置
 * Update time Unix timestamp, in seconds
 */
@property (nonatomic,copy) NSString * updateTime;
/**
 是否有相隔时间 | Is there a time interval?
 */
@property (nonatomic,assign) BOOL isHasTimeRange;
/**
 开始 (时) | Start (hours)
 */
@property (nonatomic,assign) NSInteger  startHour;
/**
 开始 (分) | Start (minutes)
 */
@property (nonatomic,assign) NSInteger  startMinute;
/**
 结束 (时) | End (hours)
 */
@property (nonatomic,assign) NSInteger  endHour;
/**
 结束 (分) | End (minutes)
 */
@property (nonatomic,assign) NSInteger  endMinute;

/**
 测量间隔,单位秒钟 | measurement Interval,unit:second
 modeType == 5，设置measurementInterval间隔才有效果
 modeType == 5, set the measurementInterval interval to have an effect
 */
@property (nonatomic,assign) NSInteger  measurementInterval;
/**
 通知类型 ： 0无效 ； 1：允许通知； 2：静默通知； 3：关闭通知
 __IDO_FUNCTABLE__.funcTable34Model.supportHrHighOrLowBtAlarm 功能表支持才有效
 */
@property (nonatomic,assign) NSInteger  notifyFlag;
/**
 智能心率过高提醒开关
 __IDO_FUNCTABLE__.funcTable34Model.supportHrHighOrLowBtAlarm 功能表支持才有效
 */
@property (nonatomic,assign) BOOL  highHeartMode;
/**
 智能心率过低提醒开关
 __IDO_FUNCTABLE__.funcTable34Model.supportHrHighOrLowBtAlarm 功能表支持才有效
 */
@property (nonatomic,assign) BOOL  lowHeartMode;
/**
 智能心率过高提醒阈值
 */
@property (nonatomic,assign) NSInteger  highHeartValue;
/**
 智能心率过低提醒阈值
 */
@property (nonatomic,assign) NSInteger  lowHeartValue;
/**
 支持秒级心率
 只获取有效，设置不需要赋值
 */
@property (nonatomic,assign) BOOL getSecondMode;
/**
 获取手表支持的心率类型集合 | get support  heart rate item type array
 分别:5s,1分钟,3分钟,5分钟,10分钟,30分钟,智能心率(255s),15分钟
 只获取有效，设置不需要赋值
 */
@property (nonatomic,copy) NSArray * hrModeTypes;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetV3HeartRateModeBluetoothModel
 */
+ (IDOSetV3HeartRateModeBluetoothModel *)currentModel;
@end

#pragma mark ====  设置运动开关 model ====
@interface IDOSetActivitySwitchBluetoothModel:IDOBluetoothBaseModel
/**
 自动识别运动类型开关 | sport type on Off
 */
@property (nonatomic,assign) BOOL sportTypeOnOff DEPRECATED_MSG_ATTRIBUTE("this attribute is discarded");
/**
 自动识别走路开关 | auto identify sport walk
 */
@property (nonatomic,assign) BOOL sportWalkOnOff;
/**
 自动识别跑步开关 | auto identify sport run
 */
@property (nonatomic,assign) BOOL sportRunOnOff;
/**
 自动识别自行车开关 | auto identify sport bicycle
 */
@property (nonatomic,assign) BOOL sportBicycleOnOff;
/**
 运动自动暂停开关 | auto pause on off
 */
@property (nonatomic,assign) BOOL autoPauseOnOff;
/**
 结束提醒开关 | end remind on off
 */
@property (nonatomic,assign) BOOL endRemindOnOff;

/**
 自动识别椭圆机开关 | auto_identify_sport_elliptical
 */
@property (nonatomic,assign) BOOL sportEllipticalOnOff;
/**
 自动识别划船机开关 | auto_identify_sport_rowing
 */
@property (nonatomic,assign) BOOL sportRowingOnOff;
/**
 自动识别游泳开关 | auto_identify_sport_swim
 */
@property (nonatomic,assign) BOOL sportSwimOnOff;

/**
 自动识别智能跳绳开关 | sport_smart_rope
 */
@property (nonatomic,assign) BOOL sportSmartRope;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetActivitySwitchBluetoothModel
 */
+ (IDOSetActivitySwitchBluetoothModel *)currentModel;

@end


#pragma mark ====  设置血氧开关控制 model ====
@interface IDOSetSpo2SwitchBluetoothModel:IDOBluetoothBaseModel
/**
 开关 | on off
 */
@property (nonatomic,assign) BOOL onOff;

/**
 开始时间 （时） | start hour
 */
@property (nonatomic,assign) NSInteger startHour;

/**
 开始时间 （分） | start minute
 */
@property (nonatomic,assign) NSInteger startMinute;

/**
 结束时间 （时） | end hour
 */
@property (nonatomic,assign) NSInteger endHour;

/**
 结束时间 （分） | end minute
 */
@property (nonatomic,assign) NSInteger endMinute;
/**
 血氧过低开关 | low spo2 on off
 */
@property (nonatomic,assign) BOOL lowOnOff;
/**
 血氧过低阈值 | low spo2 value
 */
@property (nonatomic,assign) NSInteger lowValue;

/**
 通知类型 ： 0无效 ； 1：允许通知； 2：静默通知； 3：关闭通知
 __IDO_FUNCTABLE__.funcTable35Model.spo2NotifyFlag 功能表支持才有效
 */
@property (nonatomic,assign) NSInteger notifyFlag;

/**
  测量间隔,单位分钟 IDR01项目增加app设置测量间隔

 */
@property (nonatomic,assign) NSInteger measurementInterval;

/**
 测量频率数组,单位分钟 IDR01项目增加app 获取默认测量频率数组 @[@30,@60,@120]

 */
@property (nonatomic,copy) NSArray* supportMFArray;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetSpo2SwitchBluetoothModel
 */
+ (IDOSetSpo2SwitchBluetoothModel *)currentModel;

@end

#pragma mark ====  设置呼吸训练 model ====
@interface IDOSetBreatheTrainBluetoothModel:IDOBluetoothBaseModel
/**
 每分钟呼吸次数 | Breaths per minute
 */
@property (nonatomic,assign) NSInteger frequency;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetBreatheTrainBluetoothModel
 */
+ (IDOSetBreatheTrainBluetoothModel *)currentModel;
@end

#pragma mark ====  设置走动提醒 model ====
@interface IDOSetWalkReminderBluetoothModel:IDOBluetoothBaseModel
/**
 走动提醒开关 | Walking reminder switch
 */
@property (nonatomic,assign) BOOL onOff;
/**
 目标步数 | goal step
 */
@property (nonatomic,assign) NSInteger goalStep;
/**
 开始时间（时） | start time (hours)
 */
@property (nonatomic,assign) NSInteger startHour;
/**
 开始时间（分） | start time (minutes)
 */
@property (nonatomic,assign) NSInteger startMinute;
/**
 结束时间 （时） | end time (hours)
 */
@property (nonatomic,assign) NSInteger endHour;
/**
 结束时间 （分） | end time (minutes)
 */
@property (nonatomic,assign) NSInteger endMinute;
/**
 * 重复集合 [星期一、星期二、星期三、星期四、星期五、星期六、星期日]
 * Repeat collection [monday,tuesday,wednesday,thursday,friday,saturday,sunday]
 */
@property (nonatomic,copy)NSArray<NSNumber *> * repeat;
/**
 目标时间 单位(小时)
 */
@property (nonatomic,assign) NSInteger goalTime;
/**
 通知类型  0无效 ； 1：允许通知； 2：静默通知； 3：关闭通知
 __IDO_FUNCTABLE__.funcTable38Model.walkReminderAddNotify
 */
@property (nonatomic,assign) NSInteger notifyFlag;


/** 支持走动提醒设置免提醒时间段
 __IDO_FUNCTABLE__.funcTable29Model.supportSetWalkNoReminder
 */
/**
 支持走动提醒设置免提醒时间段开关 | doNotDisturbOnOff
 */
@property (nonatomic,assign) BOOL doNotDisturbOnOff;
/**
 开始时间 （时） | start time (hour)
 */
@property (nonatomic,assign) NSInteger noDisturbStartHour;
/**
 开始时间 （分） | start time (minutes)
 */
@property (nonatomic,assign) NSInteger noDisturbStartMinute;
/**
 结束时间 （时） | end time (hour)
 */
@property (nonatomic,assign) NSInteger noDisturbEndHour;
/**
 结束时间 （分） | end time (minutes)
 */
@property (nonatomic,assign) NSInteger noDisturbEndMinute;



/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetWalkReminderBluetoothModel
 */
+ (IDOSetWalkReminderBluetoothModel *)currentModel;

@end
#pragma mark ====  设置经期提醒 model ====
@interface IDOSetMenstruationRemindBluetoothModel:IDOBluetoothBaseModel
/**
 开始日提醒 提前天数 | Start Day Reminder
 */
@property (nonatomic,assign) NSInteger startDay;
/**
 排卵日提醒 提前天数 | Ovulation Day Reminder
 */
@property (nonatomic,assign) NSInteger ovulationDay;
/**
 提醒时间 （时） | Reminder time (hours)
 */
@property (nonatomic,assign) NSInteger hour;
/**
 提醒时间 （分） | Reminder time (minutes)
 */
@property (nonatomic,assign) NSInteger minute;
/**
 易孕期 开始的时候 提前多少天提醒
 */
@property (nonatomic,assign) NSInteger pregnancyDayBeforeRemind;
/**
 易孕期 结束的时候 提前多少天提醒
 */
@property (nonatomic,assign) NSInteger pregnancyDayEndRemind;
/**
 经期结束 提前多少天提醒
 */
@property (nonatomic,assign) NSInteger menstrualDayEndRemind;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetMenstruationRemindBluetoothModel
 */
+ (IDOSetMenstruationRemindBluetoothModel *)currentModel;

@end

#pragma mark ====  设置经期 model ====
@interface IDOSetMenstruationInfoBluetoothModel:IDOBluetoothBaseModel
/**
 开关 | onoff
 */
@property (nonatomic,assign) BOOL onOff;
/**
 经期长度 | length of menstruation
 */
@property (nonatomic,assign) NSInteger menstrualLength;
/**
 经期周期 | Menstrual cycle
 */
@property (nonatomic,assign) NSInteger menstrualCycle;
/**
 最近经期年份 | Recent menstrual years
 */
@property (nonatomic,assign) NSInteger lastMenstrualYear;
/**
 最近经期月份 | Recent menstrual months
 */
@property (nonatomic,assign) NSInteger lastMenstrualMonth;
/**
 最近经期日期 | Recent menstrual date
 */
@property (nonatomic,assign) NSInteger lastMenstrualDay;
/**
 排卵日的间隔 | ovulation interval day
 */
@property (nonatomic,assign) NSInteger ovulationIntervalDay;
/**
 经期前一天 | The day before the menstrual period
 */
@property (nonatomic,assign) NSInteger ovulationBeforeDay;
/**
 经期后一天 | | One day after menstruation
 */
@property (nonatomic,assign) NSInteger ovulationAfterDay;
/**
 通知类型 0无效 ； 1：允许通知； 2：静默通知； 3：关闭通知
 __IDO_FUNCTABLE__.funcTable35Model.menstrualNotifyFlag 功能表支持才有效
 */
@property (nonatomic,assign) NSInteger notifyFlag;

/**
  经期提醒开关
 __IDO_FUNCTABLE__.funcTable35Model.supportSetMenstrualOnOff 功能表支持才有效
 */
@property (nonatomic,assign) BOOL menstrualOnOff;



/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetMenstruationInfoBluetoothModel
 */
+ (IDOSetMenstruationInfoBluetoothModel *)currentModel;

@end

#pragma mark ==== 绑定model ====
@interface IDOSetBindingInfoBluetoothModel:IDOBluetoothBaseModel
/**
 授权码长度 | Authorization code length
 */
@property (nonatomic,assign) NSUInteger authLength;

/**
 授权码 | Authorization code
 */
@property (nonatomic,copy) NSString * authCode;

/**
 加密方式版本 | encrypted version
 */
@property (nonatomic,assign) NSInteger encryptedVersion;

/**
 加密数据 固件生成 | encrypted data
 */
@property (nonatomic,copy) NSArray * encryptedData;

/**
 绑定状态 ｜ bind status
 */
@property (nonatomic,assign) NSInteger bindStatus;

/**
 加密授权码 app和手环一致 ｜ encrypted authorization code app is consistent with the bracelet
 */
@property (nonatomic,assign) BOOL codeSame;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象 (只有在授权绑定才会存储数据)
 * Query the database, if the query does not initialize the new model object (only the authorization binding will store the data)
 * @return IDOSetBindingInfoBluetoothModel
 */
+ (IDOSetBindingInfoBluetoothModel *)currentModel;
@end

#pragma mark ==== 设置设置睡眠时间段model ====
@interface IDOSetSleepPeriodInfoBluetoothModel:IDOBluetoothBaseModel

/**
 睡眠开关 | Sleep switch
 */
@property (nonatomic,assign) BOOL onOff;

/**
 开始 (时) | Start (hours)
 */
@property (nonatomic,assign) NSInteger startHour;

/**
 开始 (分) | Start (minutes)
 */
@property (nonatomic,assign) NSInteger startMinute;

/**
 结束 (时) | End (hours)
 */
@property (nonatomic,assign) NSInteger endHour;

/**
 结束 (分) | End (minutes)
 */
@property (nonatomic,assign) NSInteger endMinute;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象 | Query the database, if the query does not initialize a new model object
 * @return IDOSetSleepPeriodInfoBluetoothModel
 */
+ (IDOSetSleepPeriodInfoBluetoothModel *)currentModel;
@end

#pragma mark ==== 设置血压测量指令model ====
@interface IDOSetBpMeasureInfoBluetoothModel:IDOBluetoothBaseModel

/**
 * 参数标志 0x01:开始测量，0x02:结束测量，0x03:获得血压数据
 * Parameter flag 0x01: Start measurement, 0x02: End measurement, 0x03: Obtain blood pressure data
 */
@property (nonatomic,assign) NSInteger flag;

/**
 * 返回状态 0x00:不支持，0x01:正在测量，0x02:测量成功 0x03:测量失败 0x04:设备正在运动模式
 * Return status 0x00: Not supported, 0x01: Positive measurement, 0x02: Measurement success 0x03: Measurement failure 0x04: Device is in motion mode
 */
@property (nonatomic,assign) NSInteger status;

/**
 高压(收缩压) | High pressure (systolic pressure)
 */
@property (nonatomic,assign) NSInteger systolicBp;

/**
 低压(舒张压) | Low pressure (diastolic pressure)
 */
@property (nonatomic,assign) NSInteger diastolicBp;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetBpMeasureInfoBluetoothModel
 */
+ (IDOSetBpMeasureInfoBluetoothModel *)currentModel;
@end

#pragma mark ==== 设置心率测量指令model ====
@interface IDOSetHrMeasureInfoBluetoothModel:IDOBluetoothBaseModel

/**
 * 参数标志 0x01:开始测量，0x02:结束测量，0x03:获得数据
 * Parameter flag 0x01: Start measurement, 0x02: End measurement, 0x03: Obtain data
 */
@property (nonatomic,assign) NSInteger flag;

/**
 * 返回状态 0x00:不支持，0x01:正在测量，0x02:测量成功 0x03:测量失败 0x04:设备正在运动模式 0x05:测量中(戒指才有）
 * Return status 0x00: Not supported, 0x01: Positive measurement, 0x02: Measurement success 0x03: Measurement failure 0x04: Device is in motion mode
 */
@property (nonatomic,assign) NSInteger status;

/**
 测量数据值  | Heart rate value
 */
@property (nonatomic,assign) NSInteger value;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetHrMeasureInfoBluetoothModel
 */
+ (IDOSetHrMeasureInfoBluetoothModel *)currentModel;

@end

#pragma mark ==== 设置血氧测量指令model ====
@interface IDOSetSpo2MeasureInfoBluetoothModel:IDOBluetoothBaseModel

/**
 * 参数标志 0x01:开始测量，0x02:结束测量，0x03:获得数据
 * Parameter flag 0x01: Start measurement, 0x02: End measurement, 0x03: Obtain data
 */
@property (nonatomic,assign) NSInteger flag;

/**
 * 返回状态 0x00:不支持，0x01:正在测量，0x02:测量成功 0x03:测量失败 0x04:设备正在运动模式 0x05:测量中(戒指才有）
 * Return status 0x00: Not supported, 0x01: Positive measurement, 0x02: Measurement success 0x03: Measurement failure 0x04: Device is in motion mode
 */
@property (nonatomic,assign) NSInteger status;

/**
 测量数据值  | spo2 value
 */
@property (nonatomic,assign) NSInteger value;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetSpo2MeasureInfoBluetoothModel
 */
+ (IDOSetSpo2MeasureInfoBluetoothModel *)currentModel;
@end

#pragma mark ==== 设置表盘参数model ====
@interface IDOSetWatchDiaInfoBluetoothModel:IDOBluetoothBaseModel

/**
 表盘ID | Dial ID
 */
@property (nonatomic,assign) NSInteger dialId;

/**
 * @brief  查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetWatchDiaInfoBluetoothModel
 */
+ (IDOSetWatchDiaInfoBluetoothModel *)currentModel;
@end

#pragma mark ==== 设置马达参数model ====
@interface IDOSetStartMotorInfoBluetoothModel:IDOBluetoothBaseModel

/**
 马达状态 | Motor status
 */
@property (nonatomic,assign) NSInteger status;

/**
 马达超时时长 | Motor timeout duration
 */
@property (nonatomic,assign) NSInteger timeout;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetStartMotorInfoBluetoothModel
 */
+ (IDOSetStartMotorInfoBluetoothModel *)currentModel;
@end

#pragma mark ==== 设置传感器实时数据model ====
@interface IDOSetRealTimeSensorDataInfoBluetoothModel:IDOBluetoothBaseModel

/**
  未知传感器状态 | Unknown sensor status
 */
@property (nonatomic,assign) NSInteger gsensorStatus;

/**
 心率传感器状态 | Heart Rate Sensor Status
 */
@property (nonatomic,assign) NSInteger heartRateSensorStatus;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetRealTimeSensorDataInfoBluetoothModel
 */
+ (IDOSetRealTimeSensorDataInfoBluetoothModel *)currentModel;
@end

#pragma mark ==== 设置连接参数信息model ====
@interface IDOSetConnParamInfoBluetoothModel:IDOBluetoothBaseModel

/**
 连接模式 0x00 查模式,0x01 快速模式 ,0x02 慢速模式 | Connection mode 0x00 check mode,0x01 fast mode,0x02 slow mode
 */
@property (nonatomic,assign) NSInteger mode;

/**
 修改快速模式连接间隔 | Modify Quick Mode Connection Interval
 */
@property (nonatomic,assign) NSInteger modifConnParam;

/**
 最大间隔 | Maximum interval
 */
@property (nonatomic,assign) NSInteger maxInterval;

/**
 最小间隔 | Minimum interval
 */
@property (nonatomic,assign) NSInteger minInterval;

/**
 延迟 | Delay
 */
@property (nonatomic,assign) NSInteger slaveLatency;

/**
 连接超时 | Connection timeout
 */
@property (nonatomic,assign) NSInteger connTimeout;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetConnParamInfoBluetoothModel
 */
+ (IDOSetConnParamInfoBluetoothModel *)currentModel;
@end

#pragma mark ==== 设置GPS控制信息model ====
@interface IDOSetGpsControlInfoBluetoothModel:IDOBluetoothBaseModel

/**
 1: 控制 , 2: 查询 | 1: Control, 2: Query
 */
@property (nonatomic,assign) NSInteger operate;

/**
 * 0x01 开启log,0x02 关闭log,0x03 agps写入,0x04 agps 擦除,0x05 gps_fw 写入
 * 0x01 turns on log, 0x02 turns off log, 0x03 agps writes, 0x04 agps erases, 0x05 gps_fw writes
 */
@property (nonatomic,assign) NSInteger type;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetGpsControlInfoBluetoothModel
 */
+ (IDOSetGpsControlInfoBluetoothModel *)currentModel;
@end

#pragma mark ==== 设置GPS信息model ====
@interface IDOSetGpsConfigInfoBluetoothModel:IDOBluetoothBaseModel

/**
 0x01 冷启动,0x02 热启动  默认2 | 0x01 Cold Start, 0x02 Hot  Start Default 2
 */
@property (nonatomic,assign) NSInteger startMode;

/**
 * 操作模式,1为正常;2为低功耗;4为Balance,5为1PPS 默认1
 * Operation mode, 1 is normal; 2 is low power consumption; 4 is Balance, 5 is 1PPS   default 1
 */
@property (nonatomic,assign) NSInteger gsopOperationMode;

/**
 定位周期,默认1000 1s | Positioning period, default 1000 1s
 */
@property (nonatomic,assign) NSInteger gsopCycleMs;

/**
 * 定位星mode,1为GPS,2为GLONASS,3为1为GPS + GLONASS 默认1
 * Positioning star mode, 1 is GPS, 2 is GLONASS, 3 is 1 for GPS + GLONASS  Default 1
 */
@property (nonatomic,assign) NSInteger gnsValue;

/**
 年 | year
 */
@property (nonatomic,assign) NSInteger year;

/**
 月 | Month
 */
@property (nonatomic,assign) NSInteger month;

/**
 日 | day
 */
@property (nonatomic,assign) NSInteger day;

/**
 时 | hour
 */
@property (nonatomic,assign) NSInteger hour;

/**
 分 | minute
 */
@property (nonatomic,assign) NSInteger minute;

/**
 秒 | seconds
 */
@property (nonatomic,assign) NSInteger second;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetGpsConfigInfoBluetoothModel
 */
+ (IDOSetGpsConfigInfoBluetoothModel *)currentModel;
@end

#pragma mark ==== 设置屏幕亮度model ====
@interface IDOSetScreenBrightnessInfoBluetoothModel:IDOBluetoothBaseModel
/**
 屏幕亮度级别 (0-100) | Screen brightness level (0-100)
 */
@property (nonatomic,assign) NSInteger levelValue;
/**
 是否用户调节 | is manual
 */
@property (nonatomic,assign) BOOL isManual;
/**
 * 0x00关闭自动调整,0x01 使用环境光传感器,0x02,夜间自动调整亮度,0x03 夜间降亮度使用设置的时间
 * 0x00 turns off automatic adjustment,0x01 USES ambient light sensor,
 * 0x02, automatic adjustment of brightness at night,0x03 set time for reducing brightness at night
 */
@property (nonatomic,assign) NSInteger mode;
/**
 * 夜间自动亮度调整 0x00,无效,由固件定义,0x01关闭,0x02,夜间自动调整亮度,0x03 夜间降亮度使用设置的时间
 * Automatic overnight brightness adjustment 0x00, invalid, as defined by firmware,0x01 is off,0x02,
 * automatic night brightness adjustment,0x03 night brightness reduction USES the set time
 */
@property (nonatomic,assign) NSInteger autoAdjustNight;
/**
 开始 时钟 | start hour
 */
@property (nonatomic,assign) NSInteger startHour;
/**
 开始 分钟 | start minute
 */
@property (nonatomic,assign) NSInteger startMinute;
/**
 结束 时钟 | end hour
 */
@property (nonatomic,assign) NSInteger endHour;
/**
 结束 分钟 | end minute
 */
@property (nonatomic,assign) NSInteger endMinute;
/**
 夜间亮度 (realme项目) | night level  (0-100)
 */
@property (nonatomic,assign) NSInteger nightLevel;
/**
 显示间隔时长 单位秒 
 */
@property (nonatomic,assign) NSInteger showInterval;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetScreenBrightnessInfoBluetoothModel
 */
+ (IDOSetScreenBrightnessInfoBluetoothModel *)currentModel;
@end

#pragma mark ==== 设置天气数据model ====
@interface IDOSetWeatherDataInfoBluetoothModel:IDOBluetoothBaseModel

/**
 * 天气预报更新的时间戳 time interval since 1970 (如:1444361933)
 * Time stamp of weather forecast update time interval since 1970 (eg 14442361933)
 */
@property (nonatomic,copy) NSString * timeStr;

/**
 今天平均温度 | Average temperature today
 */
@property (nonatomic,assign) NSInteger todayTemp;

/**
 * 天气类型 | Weather type
 * 天气情况(0:其他， 1:晴， 2:多云， 3:阴，4:雨，5:暴雨，
 * 6:雷阵雨， 7:雪， 8:雨夹雪，9:台风， 10:沙尘暴, 11:夜 间晴，
 * 12:夜间多云， 13:热， 14:冷， 15:清风， 16:大风， 17:雾霭，18:阵雨, 19:多云转晴)
 * weather conditions (0: others, 1: sunny, 2: cloudy, 3: cloudy, 4: rain, 5: rainstorm,
 * 6: thunderstorm, 7: snow, 8: sleet, 9: typhoon, 10: sandstorm, 11: night clear,
 * 12: cloudy night, 13: hot, 14: cold, 15: breezy, 16: blustery, 17: mist, 18: showers, 19: cloudy to clear)
 */
@property (nonatomic,assign) NSInteger todayType;
/**
 今天最高温度 | Today's highest temperature
 */
@property (nonatomic,assign) NSInteger todayMaxTemp;
/**
 今天最小温度 | Today's minimum temperature
 */
@property (nonatomic,assign) NSInteger todayMinTemp;
/**
 湿度 | Humidity
 */
@property (nonatomic,assign) NSInteger humidity;
/**
 紫外线强度 | UV intensity
 */
@property (nonatomic,assign) NSInteger todayUvIntensity;
/**
 空气污染指数 | Air Pollution Index
 */
@property (nonatomic,assign) NSInteger todayAqi;

/**
 * 后三天天的天气集合  @{@"type":@(0),@"maxTemp":@(0),@"minTemp":@(0)}
 * Weather collection for the last three days @{@"type":@(0),@"maxTemp":@(0),@"minTemp":@(0)}
 */
@property (nonatomic,copy) NSArray<NSDictionary*>* future;
/**
 城市名称
 city name
 */
@property (nonatomic,copy) NSString * cityName;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetWeatherDataInfoBluetoothModel
 */
+ (IDOSetWeatherDataInfoBluetoothModel *)currentModel;
@end

#pragma mark ==== 设置运动快捷模式排序model ====

@interface IDOSetSportSortingItemModel:IDOBluetoothBaseModel

/**
 * 排序索引 index //排序,从1、2、3、4....,0:无效
 * 100中运动排序不需要设置此属性
 * Sort index // sort from 1, 2, 3, 4... , 0: invalid
 */
@property (nonatomic,assign) NSInteger index;
/**
 * 运动模式 | Sport mode
 */
@property (nonatomic,assign) IDO_SPORT_TYPE type;

/**
 * 0 表示图标未下载
 * 1 表示小图标已下载
 * 2 表示大图标已下载
 * 4 表示中图标已下载
 * 8 表示最小图标已下载
 * 位组合图标下载状态
 * 获取命令才有效
 */
@property (nonatomic,assign) NSInteger flag;

@end

@interface IDOSetSportSortingInfoBluetoothModel:IDOBluetoothBaseModel

/**
 操作 0：无效； 1查询； 2设置
 */
@property (nonatomic,assign) NSInteger operat;
/**
 当前已添加运动类型的索引
 funcTable37Model.set100SportSort 支持100种运动才需要赋值
 */
@property (nonatomic,assign) NSInteger currentIndex;
/**
 个数
 */
@property (nonatomic,assign) NSInteger allNum;
/**
 最少显示个数（支持100种运动才有效，设置不需要赋值，获取返回的值）
 */
@property (nonatomic,assign) NSInteger minShowNum;
/**
 最大显示个数（支持100种运动才有效，设置不需要赋值，获取返回的值）
 */
@property (nonatomic,assign) NSInteger maxShowNum;
/**
 运动模式排序集合最多8个或14个或30个或150 | Sports mode sort set up to 8 or 14 or 30 or 150
 */
@property (nonatomic,copy)NSArray <IDOSetSportSortingItemModel *>* sportSortingItems;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetSportSortingInfoBluetoothModel
 */
+ (IDOSetSportSortingInfoBluetoothModel *)currentModel;

@end

#pragma mark ==== 设置运动快捷模式model ====

@interface IDOSetSportShortcutInfoBluetoothModel:IDOBluetoothBaseModel

/**
 走路 | Walking
 */
@property (nonatomic,assign) BOOL isWalk;

/**
 跑步 | Running
 */
@property (nonatomic,assign) BOOL isRun;

/**
 骑自行车 | Cycling
 */
@property (nonatomic,assign) BOOL isByBike;

/**
 步行 | Walking
 */
@property (nonatomic,assign) BOOL isOnFoot;

/**
 游泳 | Swimming
 */
@property (nonatomic,assign) BOOL isSwim;

/**
 爬山 | Mountain climbing
 */
@property (nonatomic,assign) BOOL isMountainClimbing;

/**
 羽毛球 | Badminton
 */
@property (nonatomic,assign) BOOL isBadminton;

/**
 其他 | Other
 */
@property (nonatomic,assign) BOOL isOther;

/**
 健身 | Fitness
 */
@property (nonatomic,assign) BOOL isFitness;

/**
 动感单车 | Spinning bike
 */
@property (nonatomic,assign) BOOL isSpinning;

/**
 橄榄球 | Rugby
 */
@property (nonatomic,assign) BOOL isEllipsoid;

/**
 跑步机 | Treadmill
 */
@property (nonatomic,assign) BOOL isTreadmill;

/**
 仰卧起坐 | Sit ups
 */
@property (nonatomic,assign) BOOL isSitUp;

/**
 俯卧撑 | Push-ups
 */
@property (nonatomic,assign) BOOL isPushUp;

/**
 哑铃 | Dumbbell
 */
@property (nonatomic,assign) BOOL isDumbbell;

/**
 举重 | Weightlifting
 */
@property (nonatomic,assign) BOOL isWeightlifting;

/**
 体操 | Gymnastics
 */
@property (nonatomic,assign) BOOL isBodybuildingExercise;

/**
 瑜伽 | Yoga
 */
@property (nonatomic,assign) BOOL isYoga;

/**
 跳绳 | Jumping rope
 */
@property (nonatomic,assign) BOOL isRopeSkipping;

/**
 乒乓球 | Table tennis
 */
@property (nonatomic,assign) BOOL isTableTennis;

/**
 篮球 | Basketball
 */
@property (nonatomic,assign) BOOL isBasketball;

/**
 足球 | Football
 */
@property (nonatomic,assign) BOOL isFootball;

/**
 排球 | Volleyball
 */
@property (nonatomic,assign) BOOL isVolleyball;

/**
 网球 | Tennis
 */
@property (nonatomic,assign) BOOL isTennis;

/**
 高尔夫 | Golf
 */
@property (nonatomic,assign) BOOL isGolf;

/**
 棒球 | Baseball
 */
@property (nonatomic,assign) BOOL isBaseball;

/**
 滑雪 | Skiing
 */
@property (nonatomic,assign) BOOL isSkiing;

/**
 滑旱冰 | Roller Skating
 */
@property (nonatomic,assign) BOOL isRollerSkating;

/**
 跳舞 | Dancing
 */
@property (nonatomic,assign) BOOL isDance;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetSportShortcutInfoBluetoothModel
 */
+ (IDOSetSportShortcutInfoBluetoothModel *)currentModel;
@end

#pragma mark ==== 设置血压校准model ====
@interface IDOSetBloodPressureInfoBluetoothModel:IDOBluetoothBaseModel

/**
 舒张压 | Diastolic blood pressure
 */
@property (nonatomic,assign) NSInteger diastolic;

/**
 收缩压 | Systolic pressure
 */
@property (nonatomic,assign) NSInteger shrinkage;

/**
 * 返回校准状态  0x01.成功进入校准模式，正在校准 0x02.在运动模式, 0x03.设备忙碌 0x04.无效的状态 0x06.校准失败 0x00.校准成功
 * Return to calibration status: 0x01. Successfully entered calibration mode, calibration;
 * 0x02. In motion mode; 0x03. Device busy; 0x04. Invalid status; 0x06. Calibration failed; 0x00. Calibration successful
 */
@property (nonatomic,assign) NSInteger statusCode;

/**
 * 血压校准控制  0x01 血压校准开始 0x02 血压校准查询
 * Blood Pressure Calibration Control 0x01 Blood Pressure Calibration Start 0x02 Blood Pressure Calibration Query
 */
@property (nonatomic,assign) NSInteger flag;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetBloodPressureInfoBluetoothModel
 */
+ (IDOSetBloodPressureInfoBluetoothModel *)currentModel;

@end

#pragma mark ==== 设置快捷方式model ====
@interface IDOSetShortcutInfoBluetoothModel:IDOBluetoothBaseModel

/**
 快捷方式类型 | Shortcut Type
 */
@property (nonatomic,assign) NSInteger shortcutType;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetShortcutInfoBluetoothModel
 */
+ (IDOSetShortcutInfoBluetoothModel *)currentModel;
@end

#pragma mark ==== 设置闹钟model ====
@interface IDOSetAlarmInfoBluetoothModel:IDOBluetoothBaseModel
/**
 开关 | Switch
 */
@property (nonatomic,assign) BOOL isOpen;

/**
 是否同步 | Synchronization
 */
@property (nonatomic,assign) BOOL isSync;

/**
 是否删除 （删除或者显示） | Delete （Delete or display）
 */
@property (nonatomic,assign) BOOL isDelete;

/**
 类型 | Type
 0：起床， 1：睡觉， 2：锻炼， 3：吃药， 4：约会， 5：聚会， 6:会议，7：其他
 8：吃饭， 9：刷牙，10 :休息  11 : 课程  12: 洗澡  13:学习 14: 玩耍  42：自定义名称
 0: Get up, 1: Sleep, 2: Exercise, 3: Take medicine, 4: Date, 5: Party, 6: Meeting, 7: Other
 8: Eat, 9: Brush your teeth, 10: Rest 11: Lesson 12: Shower 13: Learning 14: Play 42: Custom Name
 */
@property (nonatomic,assign) NSInteger type;
/**
 时 | hour
 */
@property (nonatomic,assign) NSInteger hour;
/**
 分 | minute
 */
@property (nonatomic,assign) NSInteger minute;
/**
 * 重复集合 [星期一、星期二、星期三、星期四、星期五、星期六、星期日]
 * Repeat collection [monday,tuesday,wednesday,thursday,friday,saturday,sunday]
 */
@property (nonatomic,copy)NSArray<NSNumber *> * repeat;
/**
 贪睡时长 （使用延时分钟代替） | Sleepy time （Use delay minutes instead）
 */
@property (nonatomic,assign) NSInteger tsnoozeDuration;
/**
 闹钟ID | Alarm ID
 */
@property (nonatomic,assign) NSInteger alarmId;
/**
 闹钟修改的时间戳 (可以不赋值)｜ set up time stamp (can be unassigned)
 */
@property (nonatomic,copy) NSString * setTimeStamp DEPRECATED_MSG_ATTRIBUTE("this attribute is discarded");

/**
 重复闹铃次数 重复闹几次，延时开关,设置成0就是关，设置成数字就是重复几次
 Repeat the alarm for several times. Set the delay switch to 0 to turn off, and set it to a number to repeat several times
 */
@property (nonatomic,assign) NSInteger repeatTime;

/**
 震动开关
 shock on off
 */
@property (nonatomic,assign) BOOL shockOnOff;
/**
 延时分钟 （贪睡时长也使用这个字段）, 若要关闭，则 repeatTime = 0.
 delay minutes (this field is also used for snooze duration)，To close, repeatTime=0
 */
@property (nonatomic,assign) NSInteger delayMinute;
/**
 闹钟名字 长度限制 23个字节
 name
 */
@property (nonatomic,copy) NSString * alarmName;
/**
 * @brief 初始化闹钟集合 | Initialize the alarm collection
 * @return 闹钟集合 | Alarm clock collection
 */
+ (NSArray <IDOSetAlarmInfoBluetoothModel *>*)queryAllAlarms;

/**
 * @brief 查询没有被开启的闹钟集合 | Querying an alarm set that is not turned on
 * @return 闹钟集合 | Alarm clock collection
 */
+ (NSArray <IDOSetAlarmInfoBluetoothModel *>*)queryAllNoOpenAlarms;

@end

#pragma mark ==== 设置扩展v3闹钟model ====
@interface IDOSetExtensionAlarmInfoBluetoothModel:IDOBluetoothBaseModel
/**
 闹钟版本号 ｜ alarm version
 */
@property (nonatomic,assign) NSInteger alarmVersion;

/**
 闹钟个数 ｜ alarm count
 */
@property (nonatomic,assign) NSInteger alarmCount;

/**
 重复闹铃次数 重复闹几次
 */
@property (nonatomic,assign) NSInteger repeatTime DEPRECATED_MSG_ATTRIBUTE("this attribute is discarded");

/**
 延时分钟
 delay minute
 */
@property (nonatomic,assign) NSInteger delayMinute DEPRECATED_MSG_ATTRIBUTE("this attribute is discarded");

/**
闹钟集合 ｜ alarm items
*/
@property (nonatomic,copy) NSArray <IDOSetAlarmInfoBluetoothModel *>* items;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetExtensionAlarmInfoBluetoothModel
 */
+ (IDOSetExtensionAlarmInfoBluetoothModel *)currentModel;

@end

#pragma mark ==== 设置语音闹钟model ====
@interface IDOSetVoiceV3AlarmItemInfoModel : IDOBluetoothBaseModel
/**
 开关 | Switch
 */
@property (nonatomic,assign) BOOL isOpen;

/**
 显示闹钟 | Switch
 */
@property (nonatomic,assign) BOOL isShow;

/**
 年 | year
 */
@property (nonatomic,assign) NSInteger year;

/**
 月 | month
 */
@property (nonatomic,assign) NSInteger month;

/**
 日 | day
 */
@property (nonatomic,assign) NSInteger day;

/**
 时 | hour
 */
@property (nonatomic,assign) NSInteger hour;

/**
 分 | minute
 */
@property (nonatomic,assign) NSInteger minute;

/**
 * 闹钟ID  无效闹钟默认为0   设置范围0-10
 * Alarm ID Invalid alarm is 0 by default  Set the range to 0-10
 */
@property (nonatomic,assign) NSInteger alarmId;

/**
 * 重复集合 [星期一、星期二、星期三、星期四、星期五、星期六、星期日]
 * Repeat collection [monday,tuesday,wednesday,thursday,friday,saturday,sunday]
 */
@property (nonatomic,copy)NSArray<NSNumber *> * repeat;

@end

@interface IDOSetVoiceV3AlarmInfoModel : IDOBluetoothBaseModel

/**
 闹钟版本号 ｜ alarm version
 */
@property (nonatomic,assign) NSInteger alarmVersion;

/**
 闹钟个数 最多 10个 ｜ alarm count  max 10
 */
@property (nonatomic,assign) NSInteger alarmCount;

/**
闹钟集合 ｜ alarm items
*/
@property (nonatomic,copy) NSArray <IDOSetVoiceV3AlarmItemInfoModel *>* items;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetVoiceV3AlarmInfoModel
 */
+ (IDOSetVoiceV3AlarmInfoModel *)currentModel;

/**
 *解绑后清除所有语音闹钟
 *unbind clear all voice alarms
 */
+ (BOOL)unbindClearAllVoiceAlarms;

@end

#pragma mark ==== 设置时间model ====
@interface IDOSetTimeInfoBluetoothModel:IDOBluetoothBaseModel

/**
 年 | year
 */
@property (nonatomic,assign) NSInteger year;

/**
 月 | Month
 */
@property (nonatomic,assign) NSInteger month;

/**
 日 | day
 */
@property (nonatomic,assign) NSInteger day;

/**
 时 | hour
 */
@property (nonatomic,assign) NSInteger hour;

/**
 分 | minute
 */
@property (nonatomic,assign) NSInteger minute;

/**
 秒 | seconds
 */
@property (nonatomic,assign) NSInteger second;

/**
 星期 | week
 */
@property (nonatomic,assign) NSInteger weekDay;

/**
 时区(1-24)｜time zone (1-24)  -- 用24时区的，手机端的获取时区是整数，0-12东，13-24西
 功能表第36表中 =>timeZoneFloat 如果支持 时区*100 例如：8.10*100 = 810
 */
@property (nonatomic,assign) NSInteger timeZone;

/**
 当前时间戳 ｜ time stamp
 */
@property (nonatomic,copy) NSString * timeStamp;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetTimeInfoBluetoothModel
 */
+ (IDOSetTimeInfoBluetoothModel *)currentModel;

/**
 * @brief 获取当前UTC时间模型
 * get current utc time model
 * @return IDOSetTimeInfoBluetoothModel
*/
+ (IDOSetTimeInfoBluetoothModel *)getCurrentUtcTimeModel;
@end

#pragma mark ==== 设置单位model ====
@interface IDOSetUnitInfoBluetoothModel:IDOBluetoothBaseModel
/**
 距离单位 0x00:无效， 0x01:km，0x02:mi | Distance unit 0x00: Invalid, 0x01:km, 0x02:mi
 */
@property (nonatomic,assign) NSInteger distanceUnit;
/**
 重量单位 0x00: 无效，0x01:kg， 0x02:lb， 0x03: 英石 | Weight Unit 0x00: Invalid, 0x01:kg, 0x02:lb, 0x03: Stone
 */
@property (nonatomic,assign) NSInteger weightUnit;
/**
 温度单位 0x00:无效， 0x01:°C， 0x02:°F | Temperature unit 0x00: Invalid, 0x01: °C, 0x02: °F
 */
@property (nonatomic,assign) NSInteger tempUnit;

/**
 * 语言单位 , 具体类型查看 IDO_LANGUAGE_TYPE
 * Language units, specific types can be found in IDO_ LANGUAGE_ TYPE
 */
@property (nonatomic,assign) IDO_LANGUAGE_TYPE languageUnit;

/**
 * 固件默认语言单位 , 具体类型查看 IDO_LANGUAGE_TYPE
 * Language units, specific types can be found in IDO_ LANGUAGE_ TYPE
 */
@property (nonatomic,assign) IDO_LANGUAGE_TYPE defaultLanguageUnit;

/**
 * 走路步伐 根据男性换算 默认值 72 （单位 ：cm）
 * Walking pace According to male conversion Default value 72 (unit: cm)
 */
@property (nonatomic,assign) NSInteger strideWalk;

/**
 * 跑步步伐 根据男性换算 默认值 90 （单位 ：cm）
 * Running pace Converted by male Default 90 (Unit: cm)
 */
@property (nonatomic,assign) NSInteger strideRun;

/**
 * gps校准步长 0x00:无效， 0x01:开， 0x02: 关
 * gps calibration step size 0x00: invalid, 0x01: on, 0x02: off
 */
@property (nonatomic,assign) NSInteger strideGps;

/**
 * 时间单位 0x00:无效， 0x01:24 小时制，0x02: 12 小时制
 * Time unit 0x00: Invalid, 0x01: 24-hour clock, 0x02: 12-hour clock
 */
@property (nonatomic,assign) NSInteger timeUnit;

/**
 * 星期的开始日 星期日：0x01，星期一 ：0x00，星期六 ：0x03
 * Start of the week Sunday: 0x01, Monday: 0x00, Saturday: 0x03
 */
@property (nonatomic,assign) NSInteger weekStart;

/**
 * 卡路里单位设置 0x00 ：无效； 0x01 ：千卡；0x02 : 大卡； 0x03 : 千焦
 */
@property (nonatomic,assign) NSInteger calorieUnit;

/**
 * 泳池单位设置 0x00 ：无效； 0x01 ：米；0x02 : 码
 */
@property (nonatomic,assign) NSInteger swimPoolUnit;

/**
 * 骑行的单位(公里/英里)  0x00 :  无效；0x01 : km 公里   0x02 :  英里
 */
@property (nonatomic,assign) NSInteger cyclingUnit;

/**
 * 步行或者跑步的单位(公里/英里)  0x00 :  无效；0x01 : km 公里   0x02 :  英里
 */
@property (nonatomic,assign) NSInteger walkRunUnit;

/**
 步幅长度的单位设置(公制/英制) 0：无效  1：cm  2：inch 英寸
 */
@property (nonatomic,assign) NSInteger strideLengthUnit;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetUnitInfoBluetoothModel
 */
+ (IDOSetUnitInfoBluetoothModel *)currentModel;
@end

#pragma mark ==== 设置心率区间model ====
@interface IDOSetHrIntervalInfoBluetoothModel:IDOBluetoothBaseModel

/**
 燃烧脂肪 | Threshold for burning fat
 */
@property (nonatomic,assign) NSInteger burnFat;

/**
 有氧运动 | Aerobic threshold
 */
@property (nonatomic,assign) NSInteger aerobic;

/**
 极限运动 | Limit threshold
 */
@property (nonatomic,assign) NSInteger limitValue;

/**
 最大心率 | Maximum heart rate
 */
@property (nonatomic,assign) NSInteger userMaxHr;

/**
 热身运动 | Warm-up
 */
@property (nonatomic,assign) NSInteger warmUp;

/**
 无氧运动 | Anaerobic exercise
 */
@property (nonatomic,assign) NSInteger anaerobic;

/**
 最小心率 | min heart rate
 */
@property (nonatomic,assign) NSInteger minHr;

/**
 最大心率提醒开关 | Max heart rate remind
 */
@property (nonatomic,assign) BOOL maxHrRemind;

/**
 最小心率提醒开关 | Min heart rate remind
 */
@property (nonatomic,assign) BOOL minHrRemind;

/**
 提醒开始时 | remind start hour
 */
@property (nonatomic,assign) NSInteger startHour;

/**
 提醒开始分 | remind start minute
 */
@property (nonatomic,assign) NSInteger startMinute;

/**
 提醒结束时 | remind stop hour
 */
@property (nonatomic,assign) NSInteger stopHour;

/**
 提醒结束分 | remind stop minute
 */
@property (nonatomic,assign) NSInteger stopMinute;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetHrIntervalInfoBluetoothModel
 */
+ (IDOSetHrIntervalInfoBluetoothModel *)currentModel;
@end

#pragma mark ==== 设置勿扰模式model ====
@interface IDOSetNoDisturbModeInfoBluetoothModel:IDOBluetoothBaseModel

/**
 开关 | Switch
 */
@property (nonatomic,assign) BOOL isOpen;

/**
 开始 (时) | Start (hours)
 */
@property (nonatomic,assign) NSInteger  startHour;

/**
 开始 (分) | Start (minutes)
 */
@property (nonatomic,assign) NSInteger  startMinute;

/**
 结束 (时) | End (hours)
 */
@property (nonatomic,assign) NSInteger  endHour;

/**
 结束 (分) | End (minutes)
 */
@property (nonatomic,assign) NSInteger  endMinute;

/**
 * 是否有间隔重复提醒
 * interval repeat reminder
 */
@property (nonatomic,assign) BOOL  isHaveRangRepeat;

/**
 * 重复集合 [星期一、星期二、星期三、星期四、星期五、星期六、星期日]
 * Repeat collection [monday,tuesday,wednesday,thursday,friday,saturday,sunday]
 */
@property (nonatomic,copy)NSArray<NSNumber *> * repeat;

/*
午休开关 | noon time on off
*/
@property (nonatomic,assign) BOOL noonTimeOnOff;

/*
午休开始时 | noon time rest start hour
*/
@property (nonatomic,assign) NSInteger noonTimeStartHour;

/*
午休开始分 | noon time rest start minute
*/
@property (nonatomic,assign) NSInteger noonTimeStartMinute;

/*
午休结束时 | noon time rest end hour
*/
@property (nonatomic,assign) NSInteger noonTimeEndHour;

/*
午休结束分 | noon time rest end minute
*/
@property (nonatomic,assign) NSInteger noonTimeEndMinute;
/*
 全天勿扰开关 | all day on off
 __IDO_FUNCTABLE__.funcTable31Model.noDisturbAllDayOnOff 功能表支持才有效
*/
@property (nonatomic,assign) BOOL allDayOnOff;
/*
 智能勿扰开关 | smart on off
 __IDO_FUNCTABLE__.funcTable31Model.noDisturbAllDayOnOff 功能表支持才有效
*/
@property (nonatomic,assign) BOOL smartOnOff;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetNoDisturbModeInfoBluetoothModel
 */
+ (IDOSetNoDisturbModeInfoBluetoothModel *)currentModel;
@end

#pragma mark ==== 设置心率模式model ====
@interface IDOSetHrModeInfoBluetoothModel:IDOBluetoothBaseModel

/**
 * 心率模式 0:关闭心率监测功能 1:手动模式 2:自动模式 3:持续监测（默认：自动模式）
 * Heart Rate Mode 0: Turn off heart rate monitoring function 1: Manual mode 2: Auto mode 3:Continuously monitor(Default: Auto mode)
 */
@property (nonatomic,assign) NSInteger modeType;

/**
 是否有相隔时间 | Is there a time interval?
 */
@property (nonatomic,assign) BOOL isHasTimeRange;

/**
 开始 (时) | Start (hours)
 */
@property (nonatomic,assign) NSInteger  startHour;

/**
 开始 (分) | Start (minutes)
 */
@property (nonatomic,assign) NSInteger  startMinute;

/**
 结束 (时) | End (hours)
 */
@property (nonatomic,assign) NSInteger  endHour;

/**
 结束 (分) | End (minutes)
 */
@property (nonatomic,assign) NSInteger  endMinute;

/**
 测量间隔,单位分钟 | measurement Interval,unit:minutes
 */
@property (nonatomic,assign) NSInteger  measurementInterval;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetHRModeInfoBluetoothModel
 */
+ (IDOSetHrModeInfoBluetoothModel *)currentModel;

@end

#pragma mark ==== 设置手环横竖屏model ====
@interface IDOSetDisplayModeInfoBluetoothModel:IDOBluetoothBaseModel

/**
 显示模式 | Display mode
 */
@property (nonatomic,assign) NSInteger modeType;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetDisplayModeInfoBluetoothModel
 */
+ (IDOSetDisplayModeInfoBluetoothModel *)currentModel;

@end

#pragma mark ==== 设置抬腕手势model ====
@interface IDOSetHandUpInfoBuletoothModel : IDOBluetoothBaseModel

/**
 开关 | Switch
 */
@property (nonatomic,assign) BOOL isOpen;

/**
 是否有相隔时间 | Is there a time interval?
 */
@property (nonatomic,assign) BOOL isHasTimeRange;

/**
 最小显示时长 3秒 | Minimum display time of 3 seconds
 */
@property (nonatomic,assign) NSInteger  showSecond;

/**
 开始 (时) | Start (hours)
 */
@property (nonatomic,assign) NSInteger  startHour;

/**
 开始 (分) | Start (minutes)
 */
@property (nonatomic,assign) NSInteger  startMinute;

/**
 结束 (时) | End (hours)
 */
@property (nonatomic,assign) NSInteger  endHour;

/**
 结束 (分) | End (minutes)
 */
@property (nonatomic,assign) NSInteger  endMinute;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetHandUpInfoBuletoothModel
 */
+ (IDOSetHandUpInfoBuletoothModel *)currentModel;
@end

#pragma mark ==== 设置久坐提醒model ====
@interface IDOSetLongSitInfoBuletoothModel : IDOBluetoothBaseModel

/**
 开始 (时) | Start (hours)
 */
@property (nonatomic,assign) NSInteger  startHour;

/**
 开始 (分) | Start (minutes)
 */
@property (nonatomic,assign) NSInteger  startMinute;

/**
 结束 (时) | End (hours)
 */
@property (nonatomic,assign) NSInteger  endHour;

/**
 结束 (分) | End (minutes)
 */
@property (nonatomic,assign) NSInteger  endMinute;

/**
 间隔 | Interval
 */
@property (nonatomic,assign) NSInteger  interval;

/**
 开关 | Switch
 */
@property (nonatomic,assign) BOOL isOpen;

/**
  * 重复集合 [星期一、星期二、星期三、星期四、星期五、星期六、星期日]
  * Repeat collection [monday,tuesday,wednesday,thursday,friday,saturday,sunday]
 */
@property (nonatomic,copy) NSArray <NSNumber *>* selectWeeks;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetLongSitInfoBuletoothModel
 */
+ (IDOSetLongSitInfoBuletoothModel *)currentModel;
@end

#pragma mark ==== 设置天气预报开关model ====
@interface IDOSetWeatherSwitchInfoBluetoothModel:IDOBluetoothBaseModel

/**
 天气预报开关 | Weather forecast switch
 */
@property (nonatomic,assign) BOOL isOpen;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetWeatherSwitchInfoBluetoothModel
 */
+ (IDOSetWeatherSwitchInfoBluetoothModel *)currentModel;
@end

#pragma mark ==== 设置相机开关model ====
@interface IDOSetCameraInfoBluetoothModel:IDOBluetoothBaseModel

/**
 相机开关 | Camera switch
 */
@property (nonatomic,assign) BOOL isOpen;

@end

#pragma mark ==== 设置音乐开关model ====
@interface IDOSetMusicOpenInfoBuletoothModel : IDOBluetoothBaseModel

/**
 音乐开关 | Music switch
 */
@property (nonatomic,assign) BOOL isOpen;

/**
 展示歌曲信息开关 | Show music info switch
 */
@property (nonatomic,assign) BOOL showInfoStatus;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetMusicOpenInfoBuletoothModel
 */
+ (IDOSetMusicOpenInfoBuletoothModel *)currentModel;
@end

#pragma mark ==== 设置防止丢失model ====
@interface IDOSetPreventLostInfoBuletoothModel : IDOBluetoothBaseModel

/**
 防丢失级别 | Loss prevention level
 */
@property (nonatomic,assign) NSInteger levelType;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetPreventLostInfoBuletoothModel
 */
+ (IDOSetPreventLostInfoBuletoothModel *)currentModel;
@end

#pragma mark ==== 设置左右手穿戴model ====
@interface IDOSetLeftOrRightInfoBuletoothModel : IDOBluetoothBaseModel

/**
 是否右手佩戴 | Is it worn on the right hand?
 */
@property (nonatomic,assign) BOOL isRight;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetLeftOrRightInfoBuletoothModel
 */
+ (IDOSetLeftOrRightInfoBuletoothModel *)currentModel;
@end

#pragma mark ==== 设置寻找手机model ====
@interface IDOSetFindPhoneInfoBuletoothModel : IDOBluetoothBaseModel

/**
 寻找手机开关 | Looking for a phone switch
 */
@property (nonatomic,assign) BOOL isOpen;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetFindPhoneInfoBuletoothModel
 */
+ (IDOSetFindPhoneInfoBuletoothModel *)currentModel;
@end

#pragma mark ==== 设置一键呼叫model ====
@interface IDOSetOneKeySosInfoBuletoothModel : IDOBluetoothBaseModel

/**
 一键呼叫开关 | One-touch call switch
 */
@property (nonatomic,assign) BOOL isOpen;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetOneKeySosInfoBuletoothModel
 */
+ (IDOSetOneKeySosInfoBuletoothModel *)currentModel;
@end

#pragma mark ==== 设置开启蓝牙配对model ====
@interface IDOSetPairingInfoBuletoothModel : IDOBluetoothBaseModel

/**
 配对时间戳 time interval since 1970 (如:1444361933)
 * Pairing timestamp time interval since 1970 (eg 14442361933)
 */
@property (nonatomic,copy) NSString * pairingTimeStr;

/**
 是否配对 | Pairing
 */
@property (nonatomic,assign) BOOL isPairing;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetPairingInfoBuletoothModel
 */
+ (IDOSetPairingInfoBuletoothModel *)currentModel;

@end

#pragma mark ==== 设置智能提醒model ====
@interface IDOSetNoticeInfoBuletoothModel : IDOBluetoothBaseModel

/**
 ble是否配对 | Pairing
 */
@property (nonatomic,assign) BOOL isPairing;

/**
 来电延迟 | Call delay
 */
@property (nonatomic,assign) NSInteger  callDelay;

/**
 * 智能提醒总开关 (只对智能提醒有效,对来电提醒无效)
 * smart reminder switch (only valid for smart reminder, not for incoming call reminder)
 */
@property (nonatomic,assign) BOOL isOnChild;

/**
 来电提醒 | Call reminder
 */
@property (nonatomic,assign) BOOL isOnCall;

/**
 短信提醒 | SMS reminder
 */
@property (nonatomic,assign) BOOL isOnSms;

/**
 邮件提醒 | Email alert
 */
@property (nonatomic,assign) BOOL isOnEmail;

/**
 微信提醒 | WeChat reminder
 */
@property (nonatomic,assign) BOOL isOnWeChat;

/**
 qq提醒 | qq reminder
 */
@property (nonatomic,assign) BOOL isOnQq;

/**
 (国际)微博提醒 | Weibo reminder
 */
@property (nonatomic,assign) BOOL isOnWeibo;

/**
 FaceBook 提醒 | FaceBook Reminder
 */
@property (nonatomic,assign) BOOL isOnFaceBook;

/**
 Twitter 提醒 | Twitter Reminder
 */
@property (nonatomic,assign) BOOL isOnTwitter;

/**
 Whatsapp 提醒 | Whatsapp Reminder
 */
@property (nonatomic,assign) BOOL isOnWhatsapp;

/**
 Messenger 提醒 | Messenger reminder
 */
@property (nonatomic,assign) BOOL isOnMessenger;

/**
 Instagram 提醒 | Instagram reminder
 */
@property (nonatomic,assign) BOOL isOnInstagram;

/**
 LinkedIn 提醒 | LinkedIn Reminder
 */
@property (nonatomic,assign) BOOL isOnLinkedIn;

/**
 Calendar 提醒 | Calendar Reminder
 */
@property (nonatomic,assign) BOOL isOnCalendar;

/**
 Skype 提醒 | Skype reminder
 */
@property (nonatomic,assign) BOOL isOnSkype;

/**
 Alarm 提醒 | Alarm Reminder
 */
@property (nonatomic,assign) BOOL isOnAlarm;

/**
 Pokeman (其他)提醒 | Pokemon Reminder(other)
 */
@property (nonatomic,assign) BOOL isOnPokeman;

/**
 Vkontakte 提醒 | Vkontakte Reminder
 */
@property (nonatomic,assign) BOOL isOnVkontakte;

/**
 Line 提醒 | Line reminder
 */
@property (nonatomic,assign) BOOL isOnLine;

/**
 Viber 提醒 | Viber reminder
 */
@property (nonatomic,assign) BOOL isOnViber;

/**
 KakaoTalk 提醒 | KakaoTalk Reminder
 */
@property (nonatomic,assign) BOOL isOnKakaoTalk;

/**
 Gmail 提醒 | Gmail reminder
 */
@property (nonatomic,assign) BOOL isOnGmail;

/**
 Outlook 提醒 | Outlook reminder
 */
@property (nonatomic,assign) BOOL isOnOutlook;

/**
 Snapchat 提醒 | Snapchat Reminder
 */
@property (nonatomic,assign) BOOL isOnSnapchat;

/**
 Telegram 提醒 | Telegram Reminder
 */
@property (nonatomic,assign) BOOL isOnTelegram;

/**
 Chatwork 提醒 | Chatwork
 */
@property (nonatomic,assign) BOOL isOnChatwork;

/**
 Slack 提醒 | Slack
 */
@property (nonatomic,assign) BOOL isOnSlack;

/**
 Yahoo Mail 提醒 | Yahoo Mail
 */
@property (nonatomic,assign) BOOL isOnYahooMail;

/**
 Tumblr 提醒 | Tumblr
 */
@property (nonatomic,assign) BOOL isOnTumblr;

/**
 Youtube 提醒 | Youtube
 */
@property (nonatomic,assign) BOOL isOnYoutube;

/**
 Yahoo Pinterest 提醒 | Yahoo Pinterest
 */
@property (nonatomic,assign) BOOL isOnYahooPinterest;

/**
 Keep 提醒 | keep
 */
@property (nonatomic,assign) BOOL isOnKeep;

/**
 TikTok 提醒 | tiktok
 */
@property (nonatomic,assign) BOOL isOnTikTok;

/**
 Redbus 提醒 | redbus
 */
@property (nonatomic,assign) BOOL isOnRedbus;

/**
 Dailyhunt 提醒 | dailyhunt
 */
@property (nonatomic,assign) BOOL isOnDailyhunt;

/**
 Hotstar 提醒 | hotstar
 */
@property (nonatomic,assign) BOOL isOnHotstar;

/**
 Inshorts 提醒 | inshorts
 */
@property (nonatomic,assign) BOOL isOnInshorts;

/**
 Paytm 提醒 | paytm
 */
@property (nonatomic,assign) BOOL isOnPaytm;

/**
 Amazon 提醒 | amazon
 */
@property (nonatomic,assign) BOOL isOnAmazon;

/**
 Flipkart 提醒 | flipkart
 */
@property (nonatomic,assign) BOOL isOnFlipkart;

/**
 Prime 提醒 | prime
 */
@property (nonatomic,assign) BOOL isOnPrime;

/**
 Netflix 提醒 | netflix
 */
@property (nonatomic,assign) BOOL isOnNetflix;

/**
 Gpay 提醒 | gpay
 */
@property (nonatomic,assign) BOOL isOnGpay;

/**
 Phonpe 提醒 | phonpe
 */
@property (nonatomic,assign) BOOL isOnPhonpe;

/**
 Swiggy 提醒 | swiggy
 */
@property (nonatomic,assign) BOOL isOnSwiggy;

/**
 Zomato 提醒 | zomato
 */
@property (nonatomic,assign) BOOL isOnZomato;

/**
 MakeMyTrip 提醒 | make my trip
 */
@property (nonatomic,assign) BOOL isOnMakeMyTrip;

/**
 JioTv 提醒 | jio tv
 */
@property (nonatomic,assign) BOOL isOnJioTv;

/**
 Microsoft 提醒 | Microsoft
 */
@property (nonatomic,assign) BOOL isOnMicrosoft;

/**
 WhatsApp Business 提醒 | WhatsApp Business
 */
@property (nonatomic,assign) BOOL isOnWhatsAppBusiness;
/**
 nioseFit 提醒 | noiseFit
 */
@property (nonatomic,assign) BOOL isOnNioseFit;
/**
 did no call 提醒 | did no call
 */
@property (nonatomic,assign) BOOL isOnDidNotCall;
/**
 事项 提醒 | matters remind
 */
@property (nonatomic,assign) BOOL isOnMattersRemind;
/**
 uber 提醒 | uber
 */
@property (nonatomic,assign) BOOL isOnUber;
/**
 ola 提醒 | ola
 */
@property (nonatomic,assign) BOOL isOnOla;
/**
 yt music 提醒 | yt music
 */
@property (nonatomic,assign) BOOL isOnYtMusic;
/**
 google meet 提醒
 */
@property (nonatomic,assign) BOOL isOnGoogleMeet;
/**
 mormaii smartwatch 提醒
 */
@property (nonatomic,assign) BOOL isOnMormaiiSmartwatch;
/**
 technos connect 提醒
 */
@property (nonatomic,assign) BOOL isOnTechnosConnect;
/**
 enioei 提醒
 */
@property (nonatomic,assign) BOOL isOnEnioei;
/**
 aliexpress 提醒
 */
@property (nonatomic,assign) BOOL isOnAliexpress;
/**
 shopee 提醒
 */
@property (nonatomic,assign) BOOL isOnShopee;
/**
 teams 提醒
 */
@property (nonatomic,assign) BOOL isOnTeams;
/**
 99 taxi 提醒
 */
@property (nonatomic,assign) BOOL isOn99Taxi;
/**
 uber eats 提醒
 */
@property (nonatomic,assign) BOOL isOnUberEats;
/**
 l food 提醒
 */
@property (nonatomic,assign) BOOL isOnLfood;
/**
 rappi 提醒
 */
@property (nonatomic,assign) BOOL isOnRappi;
/**
 mercado Livre 提醒
 */
@property (nonatomic,assign) BOOL isOnMercadoLivre;
/**
 Magalu 提醒
 */
@property (nonatomic,assign) BOOL isOnMagalu;
/**
 Americanas 提醒
 */
@property (nonatomic,assign) BOOL isOnAmericanas;
/**
 Yahoo 提醒
 */
@property (nonatomic,assign) BOOL isOnYahoo;

/**
 Instantemail 提醒 | 支持Instantemail的功能表
 */
@property (nonatomic,assign) BOOL isOnInstantemail DEPRECATED_MSG_ATTRIBUTE("this attribute is discarded");

/**
 nhnemail 提醒 | 支持NAVER邮件的功能表
 */
@property (nonatomic,assign) BOOL isOnNhnemail DEPRECATED_MSG_ATTRIBUTE("this attribute is discarded");
/**
 zohoemail 提醒 | 支持ZoHo邮箱的功能表
 */
@property (nonatomic,assign) BOOL isOnZohoemail DEPRECATED_MSG_ATTRIBUTE("this attribute is discarded");
/**
 Exchangeemail 提醒 | 支持Exchange+ Mail Client 交换邮件的功能表
 */
@property (nonatomic,assign) BOOL isOnExchangeemail DEPRECATED_MSG_ATTRIBUTE("this attribute is discarded");
/**
 189email 提醒 | 支持189邮件的功能表
 */
@property (nonatomic,assign) BOOL isOn189email DEPRECATED_MSG_ATTRIBUTE("this attribute is discarded");
/**
 googleGmail 提醒 | 支持谷歌邮箱的功能表
 */
@property (nonatomic,assign) BOOL isOnGoogleGmail DEPRECATED_MSG_ATTRIBUTE("this attribute is discarded");
/**
 Veryfit 提醒 的功能表 0x4F
 */
@property (nonatomic,assign) BOOL isOnVeryfit;

/**
 general 提醒 | 通知支持通用的功能表 0x50
 */
@property (nonatomic,assign) BOOL isOnGeneral;
/**
 189email 提醒 |  通知支持阿里巴巴邮箱的功能表 type:0x51
 */
@property (nonatomic,assign) BOOL isOnAlibabaemail;

/**
 通知支持Calendario(谷歌日历)
 */
@property (nonatomic,assign) BOOL isOnCalendario;
/**
 通知支持Fastrack Reflex World
 */
@property (nonatomic,assign) BOOL isOnFastrackReflexWorld;
/**
 通知支持Hama Fit Move
 */
@property (nonatomic,assign) BOOL isOnHamaFitMove;
/**
 通知支持淘宝
 */
@property (nonatomic,assign) BOOL isOnTaobao;
/**
 通知支持钉钉
 */
@property (nonatomic,assign) BOOL isOnDingtalk;
/**
 通知支持支付宝
 */
@property (nonatomic,assign) BOOL isOnAlipay;
/**
 通知支持今日头条
 */
@property (nonatomic,assign) BOOL isOnToutiao;

/**
 通知支持天猫的功能表
 */
@property (nonatomic,assign) BOOL isOnTmail;
/**
 通知支持京东
 */
@property (nonatomic,assign) BOOL isOnJD;
/**
 通知支持拼多多
 */
@property (nonatomic,assign) BOOL isOnPinduoduo;
/**
 通知支持百度
 */
@property (nonatomic,assign) BOOL isOnBaidu;
/**
 通知支持美团
 */
@property (nonatomic,assign) BOOL isOnMeituan;
/**
 通知支持饿了么
 */
@property (nonatomic,assign) BOOL isOnEleme;
/**
 通知国内抖音
 */
@property (nonatomic,assign) BOOL isOnDouyin;
/**
 通知国内微博
 */
@property (nonatomic,assign) BOOL isOnHomeWeibo;
/**
 Titan Smart World定制
 */
@property (nonatomic,assign) BOOL isOnTitanSmartWorld;
/**
 RYZE定制
 */
@property (nonatomic,assign) BOOL isOnRyzeConnect;
/**
 LoopsFit定制
 */
@property (nonatomic,assign) BOOL isOnLoopsFit;
/**
 TasSmart定制
 */
@property (nonatomic,assign) BOOL isOnTasSmart;
/**
 IDW20-T定制  Facebook messenger
 */
@property (nonatomic,assign) BOOL isOnFacebookMessenger;
/**
 Nubank
 */
@property (nonatomic,assign) BOOL isOnNubank;
/**
 Bradesco
 */
@property (nonatomic,assign) BOOL isOnBradesco;
/**
 Itaú
 */
@property (nonatomic,assign) BOOL isOnItaú;
/**
 Banco do brasil
 */
@property (nonatomic,assign) BOOL isOnBancoDoBrasil;
/**
 Correios
 */
@property (nonatomic,assign) BOOL isOnCorreios;
/**
 Banco inter
 */
@property (nonatomic,assign) BOOL isOnBancoInter;
/**
 Caixa economica
 */
@property (nonatomic,assign) BOOL isOnCaixaEconomica;
/**
 Neon
 */
@property (nonatomic,assign) BOOL isOnNeon;
/**
 Santander
 */
@property (nonatomic,assign) BOOL isOnSantander;
/**
 Next
 */
@property (nonatomic,assign) BOOL isOnNext;
/**
 Shein
 */
@property (nonatomic,assign) BOOL isOnShein;
/**
 GoogleTask
 */
@property (nonatomic,assign) BOOL isOnGoogleTask;
/**
 Microsoft to do
 */
@property (nonatomic,assign) BOOL isOnMicrosoftToDo;
/**
 TickTick
 */
@property (nonatomic,assign) BOOL isOnTickTick;
/**
 Todoist
 */
@property (nonatomic,assign) BOOL isOnTodoist;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetNoticeInfoBuletoothModel
 */
+ (IDOSetNoticeInfoBuletoothModel *)currentModel;

@end

#pragma mark ==== 设置用户信息model ====
@interface IDOSetUserInfoBuletoothModel : IDOBluetoothBaseModel
/**
 身高(厘米) | Height(cm)
 */
@property (nonatomic,assign) NSInteger height;
/**
 当前体重(千克)*100 | Current weight(kg)*100
 */
@property (nonatomic,assign) NSInteger weight;
/**
 性别 1: 男 2 ：女 | Gender 1: Male 2: Female
 */
@property (nonatomic,assign) NSInteger gender;
/**
 年 | year
 */
@property (nonatomic,assign) NSInteger year;
/**
 月 | Month
 */
@property (nonatomic,assign) NSInteger month;
/**
 日 | day
 */
@property (nonatomic,assign) NSInteger day;
/**
 目标睡眠 (时) | Target sleep (hours)
 */
@property (nonatomic,assign) NSInteger goalSleepDataHour;
/**
 目标睡眠 (分) | Target sleep (minutes)
 */
@property (nonatomic,assign) NSInteger goalSleepDataMinute;
/**
 目标步数 | Target steps
 */
@property (nonatomic,assign) NSInteger goalStepData;
/**
 目标卡路里 | Goal Calories
 */
@property (nonatomic,assign) NSInteger goalCalorieData;
/**
 目标距离(米) | Target distance(m)
 */
@property (nonatomic,assign) NSInteger goalDistanceData;
/**
 中高运动时长的目标(秒) | mid high time goal(s)
 */
@property (nonatomic,assign) NSInteger goalMidHighTimeData;
/**
 活动卡路里最小值 单位：千卡
 */
@property (nonatomic,assign) NSInteger calorieMin;
/**
 活动卡路里最大值 单位：千卡
 */
@property (nonatomic,assign) NSInteger calorieMax;
/**
 走动每小时目标步数
 接口： setTargetInfoCommand
 */
@property (nonatomic,assign) NSInteger goalWalkStep;
/**
 走动目标时间 单位 时
 */
@property (nonatomic,assign) NSInteger goalWalkTime;
/**
 目标体重(千克) | Target weight(kg)
 */
@property (nonatomic,assign) NSInteger goalWeightData;
/**
 * 目标类型 (类型 : 0 : 步数  1 : 卡路里  2 : 距离) 设置一种类型的目标需要执行一次命令
 * Target type (type : 0 : step 1 : calories 2 : distance) Setting a type of target requires a command to be executed
 */
@property (nonatomic,assign) NSInteger goalType;

/**
 * 支持app设置获取运动三环周目标 | Support app settings to get the goal of the three rings of sports
 0：无效 | invalid
 1：日目标 | Daily target
 2：周目标 | Weekly target
 */
@property (nonatomic,assign) NSInteger timeGoalType;

/**
 是否登陆 | Login
 */
@property (nonatomic,assign) BOOL isLogin;

/**
 绑定状态 | Binding status
 */
@property (nonatomic,assign) NSInteger bindState;

/**
 全天步数目标达成提醒开关
 */
@property (nonatomic,assign) BOOL achievedRemindOnOff;

/**
 设置全天目标步数的UTC时间 无效值：0xFFFF 功能表: __IDO_FUNCTABLE__.funcTable42Model.supportSetStepTime
 */
@property (nonatomic,assign) NSInteger setStepTime;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetUserInfoBuletoothModel
 */
+ (IDOSetUserInfoBuletoothModel *)currentModel;


@end


@interface IDOSetInfoBluetoothModel : IDOBluetoothBaseModel

@end

#pragma mark ====  获取设置的卡路里/距离/中高运动时长的目标设置 model ====
@interface IDOSetCalorieDistanceDateGoalModel : IDOBluetoothBaseModel
/**
  0：无效 | invalid
  1：日目标 | Daily target
  2：周目标 | Weekly target
  默认值：1  |  default：1
 */
@property (nonatomic,assign) NSInteger timeGoaltype;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetBreathRateSwitchModel
 */
+ (IDOSetCalorieDistanceDateGoalModel *)currentModel;

@end

#pragma mark ====  设置语音助手开关 model ====
@interface IDOSetVoiceAssistantStatusModel : IDOBluetoothBaseModel
/**
 开关状态
 */
@property (nonatomic,assign) BOOL onOff;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetBreathRateSwitchModel
 */
+ (IDOSetVoiceAssistantStatusModel *)currentModel;

@end

#pragma mark ====  设置APP下发alexa功能开关 model ====
@interface IDOSetAlexaAoiceFunctionStatusModel : IDOBluetoothBaseModel
/**
 开关状态
 */
@property (nonatomic,assign) BOOL onOff;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetAlexaAoiceFunctionStatusModel
 */
+ (IDOSetAlexaAoiceFunctionStatusModel *)currentModel;

@end

#pragma mark ====  设置快捷来电回复开关 model ====
@interface IDOSetCallQuickStatusModel : IDOBluetoothBaseModel
/**
 开关状态
 */
@property (nonatomic,assign) BOOL onOff;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetCallQuickStatusModel
 */
+ (IDOSetCallQuickStatusModel *)currentModel;

@end

#pragma mark ====  APP控制固件屏蔽功能 VP model ====
@interface IDOSetCloseDeviceFunctionModel : IDOBluetoothBaseModel
/**
 开关状态| switch status
 true：不开启屏蔽功能 | Do not enable Shielding function
 false：开启屏蔽功能  | Enable Shielding function
 */
@property (nonatomic,assign) BOOL onOff;
/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetCloseDeviceFunctionModel
 */
+ (IDOSetCloseDeviceFunctionModel *)currentModel;

@end

#pragma mark === 关爱提醒 model ===
@interface IDOSetCareReminderTimeModel: IDOBluetoothBaseModel

/**
 年 | year
 */
@property (nonatomic, assign) NSInteger year;

/**
 月 | Month
 */
@property (nonatomic, assign) NSInteger month;

/**
 日 | day
 */
@property (nonatomic, assign) NSInteger day;

/**
 时 | hour
 */
@property (nonatomic, assign) NSInteger hour;

/**
 分 | minute
 */
@property (nonatomic, assign) NSInteger minute;

/**
 秒 | seconds
 */
@property (nonatomic, assign) NSInteger second;


@end

@interface IDOSetCareReminderDesModel: IDOBluetoothBaseModel

/**
 关爱提醒次数 | number of care reminders
 */
@property (nonatomic, assign) NSInteger careFrequency;

@end

@interface IDOSetCareReminderStateChangeModel: IDOBluetoothBaseModel
/**
 状态类型
 无效值 0
 郁闷 1
 工作中 2
 休闲 3
 下午茶 4
 忙碌 5
 假期 6
 发呆 7
 元气满满 8
 勿扰 9
 睡眠 10
 运动 11
 */

/**
 修改前的状态
 */
@property (nonatomic, assign) NSInteger orgState;

/**
 修改后的状态
 */
@property (nonatomic, assign) NSInteger curState;

@end


@interface IDOSetCareReminderItemModel: IDOBluetoothBaseModel

/**
 1:关爱提醒 2:状态变化提醒 3:睡眠不足提醒 4:经期开始提醒
 */
@property (nonatomic, assign) NSInteger type;


/**
 名字 | name
 */
@property (nonatomic, copy) NSString * name;

/**
 提醒时间 | care reminder time
 */
@property (nonatomic, strong) IDOSetCareReminderTimeModel* reminderTime;

/**
 提醒详情  type为1 需要传| care reminder details
 */
@property (nonatomic, strong) IDOSetCareReminderDesModel* careRminder;

/**
 状态变化 type为2 需要传
 */
@property (nonatomic, strong) IDOSetCareReminderStateChangeModel *stateChangeReminder;

@end

@interface IDOSetCareReminderModel: IDOBluetoothBaseModel


/**
 1:设置关爱提醒  2:查询关爱提醒 | 1: Set care reminders 2: Query care reminders
 */
@property (nonatomic, assign) NSInteger operate;

/**
 关爱提醒配置项,仅设置有效 | Care reminder configuration item, only set valid
 */
@property (nonatomic, copy) NSArray<IDOSetCareReminderItemModel*>* reminderItems;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetCloseDeviceFunctionModel
 */
+ (IDOSetCareReminderModel *)currentModel;

@end

@interface IDOSetV3MenuListModel: IDOBluetoothBaseModel

/**
 菜单排序当前显示集合
 0 =>无效 1 =>步数 2 =>心率 3=> 睡眠 4=> 拍照 5=> 闹钟 6=> 音乐 7=> 秒表 8=> 计时器
 9=> 运动模式 10=> 天气 11=> 呼吸锻炼 12=> 查找手机 13=> 压力 14=> 数据三环 15=> 时间界面 16=> 最近一次活动
 17=> 健康数据 18=> 血氧 19 =>菜单设置 20=>alexa语音提示 21=> X屏（gt01pro-X新增）22=> 卡路里 （Doro Watch新增）
 23=>距离（Doro Watch新增）24=> 一键测量 (IDW05新增) 25=> renpho health(润丰健康)(IDW12新增) 26=> 指南针 (mp01新增)
 27=> 气压高度计(mp01新增)   28=> 通话列表(蓝牙通话)(IDW13新增) 29=> 事项提醒
 0 => invalid 1 => steps 2 => heart rate 3=> sleep 4=> picture 5=> alarm clock 6=> music 7=> stopwatch 8=> timer
 9=> exercise mode 10=> weather 11=> breathing exercise 12=> find mobile phone 13=> pressure 14=> data tricycle 15=> time interface
 16=> Last activity 17=> Health data 18=> Blood oxygen 19 => Menu setting 20=> Alexa voice prompt 21=> X screen 22=> Calories
 23=> Distance 24=> One-key measurement  25=> renpho health 26=> compass 27=> barometric_altimeter  28=>Call list
 
 无排序情况,有值则显示,无值则不现实
 有排序情况,需要按照数组从0开始依次显示
 * 0x00 无效
 * 0x01 步数
 * 0x02 心率
 * 0x03 睡眠
 * 0x04 拍照
 * 0x05 闹钟
 * 0x06 音乐
 * 0x07 秒表
 * 0x08 计时器
 * 0x09 运动模式
 * 0x0A 天气
 * 0x0B 呼吸锻炼
 * 0x0C 查找手机
 * 0x0D 压力
 * 0x0E 数据三环
 * 0x0F 时间界面
 * 0x10 最近一次活动
 * 0x11 健康数据
 * 0x12 血氧
 * 0x13 菜单设置
 * 0x14 (20)aleax语音依次显示
 * 0x15 X屏（gt01pro-X新增）
 * 0x16 卡路里 （Doro Watch新增）
 * 0x17 距离   （Doro Watch新增）
 * 0x18 一键测量 (IDW05新增)
 * 0x19 renpho health(润丰健康)(IDW12新增)
 * 0x1A 指南针 (mp01新增)
 * 0x1B 气压高度计(mp01新增)
 * 0x1C    通话列表(蓝牙通话)(IDW13新增) //功能表：table32.support_call_list
 * 0x1D    事项提醒
 * 0x1E ICE(紧急联系人咨询)
 * 0x1F 最大摄氧量
 * 0x20 恢复时间
 * 0x21 有氧训练效果
 * 0x22 海拔高度
 * 0x23 身体电量
 * 0x24 世界时钟
 * 0x25 语音助手
 * 0x26 AI语音助手
 * 0x27 支付宝
*/
@property (nonatomic,strong) NSArray<NSNumber *> * itemList;


/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetCloseDeviceFunctionModel
 */
+ (IDOSetV3MenuListModel *)currentModel;



@end

#pragma mark - 跨设备数据同步
@interface IDOSetStrideDeviceInformationModel : IDOBluetoothBaseModel

/**
 步数 | step number
 */
@property (nonatomic, assign) NSInteger stepNumber;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetStrideDeviceInformationModel
 */
+ (IDOSetStrideDeviceInformationModel *)currentModel;

@end

#pragma mark - 设置习惯养成
@interface IDOSetV3HabitFormationItemModel: IDOBluetoothBaseModel

/**
 习惯类型
 无: 0, 起床: 1, 刷牙: 2, 早餐: 3, 遛狗: 4, 上学: 5, 午餐: 6, 运动: 7, 回家: 8, 晚餐: 9,
 做家务: 10, 作业: 11, 阅读: 12, 睡觉: 13 自定义类型：255
 */
@property (nonatomic, assign) NSInteger type;

/**
 习惯类型的id，ID是唯一的 不允许相同
 */
@property (nonatomic, assign) NSInteger habitId;

/**
 总开关
 */
@property (nonatomic, assign) BOOL onOff;

/**
 提醒时间(时)
 */
@property (nonatomic, assign) NSInteger hour;

/**
 提醒时间(分)
 */
@property (nonatomic, assign) NSInteger minute;

/**
 * 重复集合 [星期一、星期二、星期三、星期四、星期五、星期六、星期日]
 * Repeat collection [monday,tuesday,wednesday,thursday,friday,saturday,sunday]
 */
@property (nonatomic,copy) NSArray<NSNumber *> * repeat;

/**
 奖励
 */
@property (nonatomic, assign) NSInteger reward;

/**
 自定义习惯类型名字长度 字节数
 */
@property (nonatomic, assign) NSInteger customNameLen;

/**
 自定义习惯类型名字内容 最大长度16个字节
 */
@property (nonatomic, copy) NSString* customNameContent;

@end

@interface IDOSetV3HabitFormationModel: IDOBluetoothBaseModel

/**
 版本号
 */
@property (nonatomic, assign) NSInteger habitVersion;

/**
 操作类型 0:无效 1:增 2:删 3:查 4:改
 */
@property (nonatomic, assign) NSInteger operate;

/**
 习惯个数，最大30个
 */
@property (nonatomic, assign) NSInteger itemsNum;

/**
 习惯item
 */
@property (nonatomic, copy)  NSArray<IDOSetV3HabitFormationItemModel *>* items;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetStrideDeviceInformationModel
 */
+ (IDOSetV3HabitFormationModel *)currentModel;

@end

@interface IDOWeatherSwitchStateModel: IDOBluetoothBaseModel


@property (nonatomic, assign) BOOL isOnOff;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetStrideDeviceInformationModel
 */
+ (IDOWeatherSwitchStateModel *)currentModel;

@end

#pragma mark === V3 家庭步数  ===
@interface IDOV3SetFamilyStepItemModel : IDOBluetoothBaseModel

/**
 家庭成员的步数值
 */
@property (nonatomic, assign) NSInteger steps;

/**
 家庭成员名字
 */
@property (nonatomic, copy) NSString * name;

@end

@interface IDOV3SetFamilyStepModel : IDOBluetoothBaseModel

/**
 版本号
 */
@property (nonatomic, assign) NSInteger familyStepVersion;

/**
 操作类型 0:无效 1:发送
 */
@property (nonatomic, assign) NSInteger operate;

/**
 家庭成员个数 最多10个
 */
@property (nonatomic, assign) NSInteger itemsNum;

@property (nonatomic, copy) NSArray<IDOV3SetFamilyStepItemModel*> *items;


/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetStrideDeviceInformationModel
 */
+ (IDOV3SetFamilyStepModel *)currentModel;

@end

@interface IDOV3SetAppBaseInformationModel : IDOBluetoothBaseModel

/**
 版本号
 */
@property (nonatomic, assign) NSInteger baseInfoVersion;

/**
 操作类型 0:无效 1:发送
 */
@property (nonatomic, assign) NSInteger operate;

/**
 用户名字
 */
@property (nonatomic, copy) NSString* userName;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOSetStrideDeviceInformationModel
 */
+ (IDOV3SetAppBaseInformationModel *)currentModel;

@end

#pragma mark === V3 戒指手势控制  ===
@interface IDOV3SetGestureTypeItemModel : NSObject

/**
 手势类型 | gesture type
 
 */
@property (nonatomic, assign) NSInteger gestureType;

@end

@interface IDOV3SetGestureSubFunctionItemModel : NSObject
/**
 子功能类型 | sub function type
 */
@property (nonatomic, assign) NSInteger subFunctionType;

/**
 手势个数[最大5] ｜ gesture item count（maximum of 5）
 */
@property (nonatomic, assign) NSInteger gestureItemCount;

/**
 手势类型items ｜ gesture type items
 */
@property (nonatomic, copy) NSArray<IDOV3SetGestureTypeItemModel*> *gestureTypeItems;

@end

@interface IDOV3SetGestureFunctionItemModel : NSObject

/**
 功能开关 0xAA:打开 0x55:关闭 | function switch  0xAA: Open 0x55: Close
 */
@property (nonatomic, assign) NSInteger functionSwitch;

/**
 功能类型  | function type
 枚举值    手势控制功能(functionType)    手势控制子功能(subFunctionType)    手势类型(gestureType)
 0x01     控制通话                     0x01：接听电话 0x02：挂断电话       0x01：手掌翻转90度2次  0x02：弹2下
 0x02     控制拍照                     0x01：遥控拍照                    0x01：手掌翻转90度2次  0x02：弹2下
 0x03     控制音乐                     0x01：控制音乐下一曲               0x01：手掌翻转90度2次  0x02：弹2下
 */
@property (nonatomic, assign) NSInteger functionType;

/**
 手势子功能个数[最大5] | gesture sub function count (maximum of 5）
 */
@property (nonatomic, assign) NSInteger gestureSubFunctionCount;

/**
 手势子功能items | gesture sub function items
 */
@property (nonatomic, copy) NSArray<IDOV3SetGestureSubFunctionItemModel*>* gestureSubFunctionItems;


@end

@interface IDOV3SetGestureControlModel : IDOBluetoothBaseModel

/**
 版本号 默认0x00 | The default version number is 0x00
 */
@property (nonatomic, assign) NSInteger gcVersion;

/**
 0x01:设置  0x02:获取 0x03:获取支持配置项 | 0x01:Set  0x02:Get  0x03:Get a supported configuration
 */
@property (nonatomic, assign) NSInteger operate;

/**
 手势控制开关 0xAA:开  0x55:关 | Gesture control switch 0xAA: On 0x55: Off
 */
@property (nonatomic, assign) NSInteger onOff;

/**
 手势功能的个数[最大10] | Number of gesture functions [Max 10]
 */
@property (nonatomic, assign) NSInteger functionItemCount;

/**
 手势功能items | Gesture function items
 */
@property (nonatomic, copy) NSArray<IDOV3SetGestureFunctionItemModel*>* functionItems;

/**
 支持的手势功能配置项 获取支持的配置项才有效| Supported Gesture function configuration options
 */
@property (nonatomic, copy) NSArray<IDOV3SetGestureFunctionItemModel*>* supportFunctionItems;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return IDOV3SetGestureControlModel
 */
+ (IDOV3SetGestureControlModel *)currentModel;

@end
