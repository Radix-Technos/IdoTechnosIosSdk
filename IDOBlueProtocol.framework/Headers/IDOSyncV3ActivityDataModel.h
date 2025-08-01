//
//  IDOSyncV3ActivityDataModel.h
//  IDOBlueProtocol
//
//  Created by hedongyang on 2020/6/1.
//  Copyright © 2020 何东阳. All rights reserved.
//

#if __has_include(<IDOBlueProtocol/IDOBlueProtocol.h>)
#else
#import "IDOBluetoothBaseModel.h"
#endif

@interface IDOSyncV3ActivityDataInfoBluetoothModel : IDOBluetoothBaseModel

/**
 年份 | Year
 */
@property (nonatomic,assign) NSInteger year;

/**
 月份 | Month
 */
@property (nonatomic,assign) NSInteger month;

/**
 日期 | Date
 */
@property (nonatomic,assign) NSInteger day;

/**
 时 | hour
 */
@property (nonatomic,assign) NSInteger hour;

/**
 分 | minutes
 */
@property (nonatomic,assign) NSInteger minute;

/**
 秒 | seconds
 */
@property (nonatomic,assign) NSInteger second;

/**
 日期 精确到日期 date interval since 1970 (如:1444361933) | Date time interval since 1970 (eg 14442361933)
 */
@property (nonatomic,copy) NSString * dateStr;

/**
 开始时间 精确到秒 | start time interval since 1970 (eg 14442361933)
 */
@property (nonatomic,copy) NSString * timeStr;

/**
 数据长度 | Data length
 */
@property (nonatomic,assign) NSInteger  dataLength;

/**
 心率数据产生间隔 (单位 : s) | Heart rate data generation interval (unit: s)
 */
@property (nonatomic,assign) NSInteger hrInterval;

/**
 心率项数据个数 | Heart rate item data
 */
@property (nonatomic,assign) NSInteger  hrItemCount;

/**
 包的总数 | Total number of packages
 */
@property (nonatomic,assign) NSInteger  packetCount;

/*
 * 运动模式 | Sport mode
 * 具体查看描述IDO_SPORT_TYPE
 */
@property (nonatomic,assign) IDO_SPORT_TYPE type;

/**
 *计划类型：1：跑步计划3km ，2：跑步计划5km ，3：跑步计划10km ， 4：半程马拉松训练（二期） ，5：马拉松训练（二期）
 *64 : 6分钟轻松跑 , 65：10分钟轻松跑  ，66：15分钟轻松跑 ，67：走跑结合初级 ，68：走跑结合进阶 ，69：走跑结合强化
 *128: 跑后拉伸
 */
@property (nonatomic,assign) NSInteger planType;

/**
 步数(骑行 时，步数为 0) | Number of steps (when riding, the number of steps is 0)
 */
@property (nonatomic,assign) NSInteger step;

/**
 持续时长 (单位:s) | Duration (unit: s)
 */
@property (nonatomic,assign) NSInteger durations;

/**
 卡路里(单 位:大卡) | Calories (Unit: Big Card)
 */
@property (nonatomic,assign) NSInteger calories;

/**
 距离(单位: 米) | Distance (in meters)
 */
@property (nonatomic,assign) NSInteger distance;

/**
 课内卡路里 (单 位:大卡) | in class Calories (Unit: Big Card)
 */
@property (nonatomic,assign) NSInteger inClassCalories;

/**
 动作完成率 0-100
 */
@property (nonatomic,assign) NSInteger completionRate;

/**
 心率控制率  0—100
 */
@property (nonatomic,assign) NSInteger hrCompletionRate;

/**
 热身表现 0-100 需要功能表支持,bool supportWarmUpBeforeRun; //支持跑前热身
 */
@property (nonatomic,assign) NSInteger warmUpPerformance;

/**
 平均心率 | Average heart rate
 */
@property (nonatomic,assign) NSInteger  avgHrValue;

/**
 最大心率 | Maximum heart rate
 */
@property (nonatomic,assign) NSInteger  maxHrValue;

/**
 脂肪燃烧时长 | Fat burning time
 */
@property (nonatomic,assign) NSInteger burnFatMins;

/**
 心肺锻炼时长 [有氧运动时长] (分钟) | Cardio workout time (minutes)
 */
@property (nonatomic,assign) NSInteger aerobicMins;

/**
 极限锻炼时长 (分钟) | Extreme workout time (minutes)
 */
@property (nonatomic,assign) NSInteger limitMins;

/**
 无氧锻炼时长 (分钟) | Anaerobic workout time (minutes)
 */
@property (nonatomic,assign) NSInteger anaerobicMins;

/**
 热身锻炼时长 (分钟) | Warm up workout time (minutes)
 */
@property (nonatomic,assign) NSInteger warmUpMins;

/**
 有序列号的心率集合 json字符串 | Heart rate collection with serial number json string
 */
@property (nonatomic,copy) NSArray  * hrValuesStr;

/**
 每分钟保存数据集合 json字符串 最大保存6小时 | Save the data  of minute for a maximum of 6 hours
 @{@"steps":@(steps),@"calories":@(calories),@"distance":@(distance)}
 */
@property (nonatomic,copy) NSArray  * dataValuesStr;

/**
 是否需要保存数据 (用于数据交换) | Do you need to save data (for data exchange)
 */
@property (nonatomic,assign) BOOL isSave;

/**
 *0:无效， 1 : app发起的运动， 2：手表发起的运动
 */
@property (nonatomic,assign) NSInteger startFrom;


/*
 * 平均速度  km/h  固件是 扩大100倍传输
 * app收到数据需要除于100，即保留2位小数
 * avg speed Km/h firmware is 100 times larger
 * The data received by app should be divided by 100, that is, 2 decimal places should be reserved
 */
@property (nonatomic,assign) NSInteger avgSpeed;

/*
* 最大速度  km/h  固件是 扩大100倍传输
* app收到数据需要除于100，即保留2位小数
* max speed Km/h firmware is 100 times larger
* The data received by app should be divided by 100, that is, 2 decimal places should be reserved
*/
@property (nonatomic,assign) NSInteger maxSpeed;

/**
 平均配速
 avg km speed
 */
@property (nonatomic,assign) NSInteger avgKmSpeed;

/**
 最快配速
 fast km speed
 */
@property (nonatomic,assign) NSInteger fastKmSpeed;

/*
平均步频
avg step frequency
*/
@property (nonatomic,assign) NSInteger avgStepFrequency;

/*
最大步频
max step frequency
*/
@property (nonatomic,assign) NSInteger maxStepFrequency;

/*
平均步幅
avg step stride
*/
@property (nonatomic,assign) NSInteger avgStepStride;

/*
最大步幅
max step stride
*/
@property (nonatomic,assign) NSInteger maxStepStride;

/**
 热身锻炼时长 (秒钟) | Warm-up time (seconds)
 */
@property (nonatomic,assign) NSInteger warmUpHrTime;

/**
 脂肪锻炼时长 (秒钟) | Fat workout Duration (seconds)
 */
@property (nonatomic,assign) NSInteger burnFatHrTime;

/**
 心肺锻炼时长 (秒钟)  | Cardio duration (seconds)
 */
@property (nonatomic,assign) NSInteger aerobicHrTime;

/**
 无氧锻炼时长 (秒钟) | Duration of anaerobic exercise (seconds)
 */
@property (nonatomic,assign) NSInteger anaerobicHrTime;

/**
 极限锻炼时长 (秒钟) | Extreme workout Duration (seconds)
 */
@property (nonatomic,assign) NSInteger limitHrTime;

/**
  每公里的配速集合json，最大公里数100公里 s钟数据传输 一公里用了多少s
  Seconds per kilometer
 */
@property (nonatomic,strong)  NSArray * kmSpeedItems;

/**
  步频集合
  frequency items
 */
@property (nonatomic,strong)  NSArray * frequencyItems;

/**
 每英里的配速集合json
 */
@property (nonatomic,strong) NSArray * mileSpeedItems;

/**
 *手环是否连接app  1是连接，0是未连接
 *Whether the bracelet is connected to APP 1 is connected, 0 is not connected
 */
@property (nonatomic,assign) NSInteger connectApp;

/**
 平均配速 传过来的是s钟， 比如361  361/60=6分 余数是1s  6''1'  , 公里和英里是按照 英里= 公里*1609/1000f
 */
@property (nonatomic,assign) NSInteger avgPaceSpeed;

/**
 最快配速
 */
@property (nonatomic,assign) NSInteger fastPaceSpeed;

/**
 训练效果；  单位：无   范围 1.0 ~ 5.0 （*10倍）
 */
@property (nonatomic,assign) NSInteger trainingEffect;
/**
 最大摄氧量；  单位：毫升/公斤/分钟； 范围  0-80  不放大100倍
 */
@property (nonatomic,assign) NSInteger vo2Max;

/**
 摄氧量等级  1:低等   2:业余   3:一般  4：平均    5：良好  6：优秀   7：专业
 */
@property (nonatomic,assign) NSInteger grade;
/**
 恢复时间点年
 */
@property (nonatomic,assign) NSInteger recoveryTimeYear;

/**
 恢复时间点月
 */
@property (nonatomic,assign) NSInteger recoveryTimeMon;

/**
 恢复时间点日
 */
@property (nonatomic,assign) NSInteger recoveryTimeDay;

/**
 恢复时间点时
 */
@property (nonatomic,assign) NSInteger recoveryTimeHour;

/**
 恢复时间点分
 */
@property (nonatomic,assign) NSInteger recoveryTimeMin;

/**
 恢复时间点秒
 */
@property (nonatomic,assign) NSInteger recoveryTimeSecond;

/**
 运动结束时间 月
 */
@property (nonatomic,assign) NSInteger endMonth;

/*
 运动结束时间 日
 */
@property (nonatomic,assign) NSInteger endDay;

/**
 运动结束时间 时
 */
@property (nonatomic,assign) NSInteger endHour;

/**
 运动结束时间 分
 */
@property (nonatomic,assign) NSInteger endMinute;

/**
 最小心率值
 */
@property (nonatomic,assign) NSInteger minHrValue;

/**
 实时配速数组  传过来的是 s 钟  每5s算一次
 */
@property (nonatomic,strong) NSArray * paceSpeedItems;

/**
 桨次数组 一分钟保存一次
 */
@property (nonatomic,strong) NSArray * paddleNumberItems;

/**
 桨频数组 一分钟保存一次 存平均值
 */
@property (nonatomic,strong) NSArray * paddleFrequencyItems;

/**
 踏频数组 一分钟保存一次 存平均值
 */
@property (nonatomic,strong) NSArray * treadFrequencyItems;

/**
 实时速度集合  单位  千米/小时  5s出一个值
 __IDO_FUNCTABLE__.funcTable31Model.activitySyncRealTime 功能表支持才有效
 */
@property (nonatomic,strong) NSArray * realSpeedItems;

/**
 动作详情集合
 * type: 动作类型（十进制）  1快走；2慢跑；3中速跑；4快跑 ；
 * 71左腿前测拉伸；72右腿前测拉伸；73左腿后侧拉伸；74右腿后侧拉伸；75左腿弓步拉伸；76右腿弓步拉伸；
 * 77左腿内侧拉伸；78右腿内侧拉伸；79左侧小腿拉伸；80右侧小腿拉伸
 * actualTime : 实际运动时间
 * goalTime : 目标时间 单位 s
 * heartValue : 心率控制值
 */
@property (nonatomic,strong) NSArray<NSDictionary *> * actionItems;

/**
 训练的课程日期偏移 从0开始
 */
@property (nonatomic,assign) NSInteger trainingOffset;

/**
 3d距离 单位km
 */
@property (nonatomic,assign) NSInteger distance3d;
/**
 平均3d速度 单位km/h
 */
@property (nonatomic,assign) NSInteger avg3dSpeed;
/**
 平均垂直速度 单位m/h
 */
@property (nonatomic,assign) NSInteger avgVerticalSpeed;

/**
 平均坡度        单位度 0 ~ 90
 */
@property (nonatomic,assign) NSInteger avgSlope;
/**
 最高海拔高度 单位米 -500 ~ 9000
 */
@property (nonatomic,assign) NSInteger maxAltitude;
/**
 最低海拔高度 单位米 -500 ~ 9000
 */
@property (nonatomic,assign) NSInteger minAltitude;
/**
 累计海拔上升 单位米
 */
@property (nonatomic,assign) NSInteger cumulativeAltitudeRise;
/**
 累计海拔下降 单位米
 */
@property (nonatomic,assign) NSInteger cumulativeAltitudeLoss;
/**
 海拔高度详情个数
 */
@property (nonatomic,assign) NSInteger altitudeCount;
/**
 海拔高度数据 30s(MP01), 一组值 单位米 范围-500~9000 最大保存12小时
 */
@property (nonatomic,strong) NSArray* altitudeItems;

/**
 平均海拔高度 单位米 -500 ~ 9000
 */
@property (nonatomic,assign) NSInteger avgAltitude;


/** 结束时间：年
 //功能表：__IDO_FUNCTABLE__.funcTable29Model.v3ActivityEndTimeUseUtc
 //同步v3多运动活动数据结束时间原字段(end_month&end_day&end_hour&end_minute)收回,使用时间戳点形式上报app
 */
@property (nonatomic,assign) NSInteger endYear;
/** 结束时间：秒
 //功能表：__IDO_FUNCTABLE__.funcTable29Model.v3ActivityEndTimeUseUtc
 //同步v3多运动活动数据结束时间原字段(end_month&end_day&end_hour&end_minute)收回,使用时间戳点形式上报app
 */
@property (nonatomic,assign) NSInteger endSec;

/**
 GPS状态 0:无效 1:开启 2:未开启(未开启时展示`距离` 开启则展示`3D距离`)
 */
@property (nonatomic,assign) NSInteger gpsStatus;


//--------------- version=0x40新增字段 ---------------
/**
 无氧训练效果 单位：无 范围： 1.0 - 5.0（扩大10倍传输）
 */
@property (nonatomic,assign) NSInteger anaerobicTrainingEffect;
/**
 负荷 无单位
 */
@property (nonatomic,assign) NSInteger load;
/**
 跑力指数 一位小数 x10传输
 */
@property (nonatomic,assign) NSInteger runningEconomy;
/**
 最大跑步功率 单位瓦 0-1500W
 */
@property (nonatomic,assign) NSInteger maxRunningPower;
/**
 最小跑步功率 单位瓦 0-1500W
 */
@property (nonatomic,assign) NSInteger minRunningPower;
/**
 平均跑步功率 单位瓦 0-1500W
 */
@property (nonatomic,assign) NSInteger avgRunningPower;
/**
 跑步功率详情个数
 */
@property (nonatomic,assign) NSInteger runningPowerCount;
/**
 实时体力RTPE(real-time physical exertion)详情个数
 */
@property (nonatomic,assign) NSInteger rtpeCount;
/**
 最大实时摄氧量
 */
@property (nonatomic,assign) NSInteger maxRtoc;
/**
 最小实时摄氧量
 */
@property (nonatomic,assign) NSInteger minRtoc;
/**
 平均实时摄氧量
 */
@property (nonatomic,assign) NSInteger avgRtoc;
/**
 实时摄氧量RTOC(real-time oxygen consumption)详情个数
 */
@property (nonatomic,assign) NSInteger rtocCount;
/**
 最快跳绳频率
 */
@property (nonatomic,assign) NSInteger maxRopeFrequency;
/**
 最慢跳绳频率
 */
@property (nonatomic,assign) NSInteger minRopeFrequency;
/**
 平均跳绳频率
 */
@property (nonatomic,assign) NSInteger avgRopeFrequency;
/**
 最多跳绳连跳次数
 */
@property (nonatomic,assign) NSInteger maxRopeSkipCount;
/**
 绊绳次数
 */
@property (nonatomic,assign) NSInteger ropeTripCount;
/**
 总跳绳次数
 */
@property (nonatomic,assign) NSInteger totalRopeCount;
/**
 跳绳详情个数
 */
@property (nonatomic,assign) NSInteger ropeItemCount;

/**
 跑步功率详情 单位瓦 0-1500W
 */
@property (nonatomic,strong) NSArray<NSNumber *> * runningPowerItems;
/**
 实时体力RTPE(real-time physical exertion)详情 0-100百分比
 */
@property (nonatomic,strong) NSArray<NSNumber *> * rtpeItems;
/**
 实时摄氧量RTOC(real-time oxygen consumption)详情 0-9999 单位ml/min
 */
@property (nonatomic,strong) NSArray<NSNumber *> * rtocItems;
/**
 跳绳详情
 每次连跳次数:  rope_skip_count;
 时长 单位秒: duration;
 */
@property (nonatomic,strong) NSArray<NSDictionary *> * ropeItems;

//--------------- 智能陪跑 ---------------

/**
  0:无效 1:非智能陪跑运动 2:智能陪跑运动
  0: Invalid 1: Non intelligent running sports 2: Intelligent running sports
 */
@property (nonatomic,assign) NSInteger smartCompetitor;
/**
 ai形象ID
 AI Image ID
 */
@property (nonatomic,assign) NSInteger aiImageId;

/**
 用户形象ID
 user image id
 */
@property (nonatomic,assign) NSInteger userImageId;

/**
 背景形象ID
 bg image id
 */
@property (nonatomic,assign) NSInteger bgImageId;

/**
 智能陪跑对手配速
 Intelligent companion running at opponent's pace
 */
@property (nonatomic,assign) NSInteger smartCompetitorPace;

/**
 最小步幅
 */
@property (nonatomic,assign) NSInteger minStepStride;

/**
 恢复心率个数
 */
@property (nonatomic,assign) NSInteger recoveryHrCount;

/**
 恢复心率数组 恢复心率2分钟，1s一个值，最多120个
 */
@property (nonatomic,copy) NSArray<NSNumber *> * recoveryHrItems;

/**
 桨次个数 根据运动类型判断有效 预留字段
 */
@property (nonatomic,assign) NSInteger paddleNumberCount;

/**
 桨频个数 预留字段
 */
@property (nonatomic,assign) NSInteger paddleFrequencyCount;    

/**
 总桨次
 */
@property (nonatomic,assign) NSInteger totalPaddleNumber;

/**
 最快桨频
 */
@property (nonatomic,assign) NSInteger maxPaddleFrequency;

/**
 最慢桨频
 */
@property (nonatomic,assign) NSInteger minPaddleFrequency;

/**
 平均桨频
 */
@property (nonatomic,assign) NSInteger avgPaddleFrequency;

/**
 运动结束的UTC时间
 */
@property (nonatomic,assign) NSInteger utcEndTime;

/**
 恢复心率起始时间点
 */
@property (nonatomic,assign) NSInteger recoveryHrStartTime;

/**
 保存实时配速个数模式 0x01:1秒保存一个 0x05:5秒保存一个
 */
@property (nonatomic,assign) NSInteger realPaceSaveInterval;

/**
 V60 版本恢复心率
 */
@property (nonatomic, copy) NSArray<NSDictionary*>* recoveryHrItemsV60;

/**
 V60 版本间歇训练
 NSArray<NSDictionary*>* intervalItemsV60 = @[
     @{
         @"stage_type": @(1),//当前训练步骤类型
         @"repeat_num": @(0),//当前重复次数
         @"stage_data_num": @(0), //当前阶段数据项个数,最大10个
         @"stage_data_type_0x60":
             @[
                 @{
                     @"stage_support_type": @(0),//当前训练步骤的训练数据类型
                     @"stage_data_value": @(0)//时间值单位s，距离单位m, 卡路里单位大卡, 配速单位s/km， 速度单位km/h乘以100倍
                 }
             ]//当前训练步骤的训练数据
     }
 ];
 训练步骤类型    索引值
 无(无效)    0x00
 热身    0x01
 训练    0x02
 休息    0x03
 放松    0x04
 
 训练步骤支持的数据类型    索引值
 无(无效)    0x00
 持续时间    0x01
 平均心率    0x02
 距离    0x03
 卡路里    0x04
 平均配速    0x05
 平均速度    0x06
 */
@property (nonatomic, copy) NSArray<NSDictionary*>* intervalItemsV60;

/**
 V60版本 间歇训练详情个数,当前阶段item最大个数110
 */
@property (nonatomic,assign) NSInteger interval_train_item_count;

/**
 V60版本后的实时配速个数使用这个字段
 */
@property (nonatomic,assign) NSInteger pace_count_new;

/**
 V60版本 圈距
 */
@property (nonatomic,assign) NSInteger circleDistance;

/**
 V60版本 最小步频
 */
@property (nonatomic,assign) NSInteger minStepFrequency;

/**
 V60版本 最慢公里配速 s/km
 */
@property (nonatomic,assign) NSInteger slowestKmPace;

@end

@interface IDOSyncV3ActivityDataModel : NSObject

/**
 * @brief 当前设备根据活动开始时间查询某个活动详情
 * The current device queries an event details based on the event start time
 * @param macAddr  mac地址 | Mac address
 * @param timeStr 活动开始时间 | Event start time
 * @return model IDOSyncV3ActivityDataInfoBluetoothModel
 */
+ (IDOSyncV3ActivityDataInfoBluetoothModel *)queryOneV3ActivityDataWithTimeStr:(NSString *)timeStr
                                                                       macAddr:(NSString *)macAddr;

/**
 * @brief 当前设备根据日期查询某天的活动集合
 * The current device queries the collection of events for a certain day based on the date
 * @param macAddr  mac地址 | Mac address
 * @param year  年份 | year
 * @param month 月份 | month
 * @param day   日期 | day
 * @return 活动集合 | Activity collection
 */
+ (NSArray <IDOSyncV3ActivityDataInfoBluetoothModel *>*)queryOneDayV3ActivityDataWithMacAddr:(NSString *)macAddr
                                                                                         year:(NSInteger)year
                                                                                        month:(NSInteger)month
                                                                                          day:(NSInteger)day;


/**
 * @brief 当前设备根据日期查询某月的活动集合
 * The current device queries the collection of events for a certain month based on the date
 * @param macAddr  mac地址 | Mac address
 * @param year  年份 | year
 * @param month 月份 | month
 * @return 活动集合 | Activity collection
 */
+ (NSArray <IDOSyncV3ActivityDataInfoBluetoothModel *>*)queryOneMonthV3ActivityDataWithMacAddr:(NSString *)macAddr
                                                                                           year:(NSInteger)year
                                                                                          month:(NSInteger)month;


/**
 * @brief 当前设备根据日期查询某年的活动集合
 * The current device queries the collection of events for a certain year based on the date
 * @param macAddr  mac地址 | Mac address
 * @param year  年份 | year
 * @return 活动集合 | Activity collection
 */
+ (NSArray <IDOSyncV3ActivityDataInfoBluetoothModel *>*)queryOneYearV3ActivityDataWithMacAddr:(NSString *)macAddr
                                                                                         year:(NSInteger)year;


/**
 * @brief 当前设备活动分页查询活动集合 | Current Device Activity Paging Query Activity Collection
 * @param pageIndex 页码 第几页 (如 : 0,1,2,3,4,...) | Page Number of pages (eg : 0,1,2,3,4,...)
 * @param numOfPage 每页的数据个数 (如 : 10,20,30...) | The number of data per page (eg: 10, 20, 30...)
 * @param macAddr  mac地址 | Mac address
 * @return 活动集合
 */
+ (NSArray <IDOSyncV3ActivityDataInfoBluetoothModel *>*)queryOnePageV3ActivityDataWithPageIndex:(NSInteger)pageIndex
                                                                                      numOfPage:(NSInteger)numOfPage
                                                                                        macAddr:(NSString *)macAddr;

/**
 * @brief 当前设备所有轨迹运动 | Current track motion of all devices
 * @param macAddr mac 地址 | mac address
 * @return 活动集合 | Activity collection
 */
+ (NSArray <IDOSyncV3ActivityDataInfoBluetoothModel *>*)queryAllTrajectorySportV3ActivitysWithMac:(NSString *)macAddr;

/**
 * @brief 当前设备所有轻运动 | Current equipment all light sports
 * @param macAddr mac 地址 | mac address
 * @return 活动集合 | Activity collection
 */
+ (NSArray <IDOSyncV3ActivityDataInfoBluetoothModel *>*)queryAllLightSportV3ActivitysWithMac:(NSString *)macAddr;

/**
 * 将json数据转模型数据 | Convert json data to model data
 * 功能表：__IDO_FUNCTABLE__.funcTable29Model.v3SyncActivity , 如果为YES，返回IDOBluetoothBaseModel的类型是IDOSyncV3ActivityDataInfoBluetoothModel ，否则返回IDOSyncActivityDataInfoBluetoothModel
 * @param jsonString  数据
 */
+(IDOBluetoothBaseModel*)v3ActivityDataJsonStringToObjectModel:(NSString*)jsonString;

@end
