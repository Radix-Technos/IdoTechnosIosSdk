//
//  IDODataExchangeModel.h
//  IDOBluetooth
//
//  Created by apple on 2018/10/5.
//  Copyright © 2018年 apple. All rights reserved.
//

#if __has_include(<IDOBlueProtocol/IDOBlueProtocol.h>)
#else
#import "IDOBluetoothBaseModel.h"
#endif

@interface IDODataExchangeModel : IDOBluetoothBaseModel
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
 秒 | second
 */
@property (nonatomic,assign) NSInteger second;
/**
 运动类型 | sport type
 具体描述请查看 IDO_SPORT_TYPE
 */
@property (nonatomic,assign) IDO_SPORT_TYPE sportType;
/**
 目标类型 | target type
 0x00:无目标， 0x01:重复次数，单位：次，
 0x02:距离,单位：米,  0x03：卡路里, 单位：大卡,
 0x04:时长,单位：分钟, 0x05:  步数, 单位：步
 */
@property (nonatomic,assign) NSInteger targetType;
/**
 目标数值 | target value
 */
@property (nonatomic,assign) NSInteger targetValue;
/**
 是否强制开始 0:不强制,1:强制 | is mandatory start
 */
@property (nonatomic,assign) NSInteger forceStart;
/**
 * 0:成功; 1:设备已经进入运动模式失败;2: 设备电量低失败;3:手环正在充电4:正在使用Alexa 5:通话中 6:设备处于锁屏状态
 * 0:success 1:into sport mode failed 2:Low power of equipment 3: the bracelet is charging 4:Using Alexa 5:In the call
 */
@property (nonatomic,assign) NSInteger retCode;
/**
 * 0x01:请求app打开gps   0x02：发起运动开始请求 0x03:发起运动开始后台联动请求
 */
@property (nonatomic,assign) NSInteger operate;
/**
 status:0:全部有效, 1:距离无效， 2: gps 信号弱 | status 0:all effective 1:distance invalid 2:gps signal weak
 */
@property (nonatomic,assign) NSInteger status;

/**
 v3Status 手环返回的状态 开始:1,暂停:2, 结束:3,0:无效状态
 starts with :1, pauses :2, ends with :3,0: invalid status
 */
@property (nonatomic,assign) NSInteger v3Status;
/**
 0:成功; 1:设备已经进入运动模式失败 | 0:success 1:into sport mode failed
 */
@property (nonatomic,assign) NSInteger errorCode;
/**
 步数 (单位:步) | step
 */
@property (nonatomic,assign) NSInteger step;
/**
 卡路里 (单位:J) | calories
 */
@property (nonatomic,assign) NSInteger calories;
/**
 距离 (单位:米) | distance
 */
@property (nonatomic,assign) NSInteger distance;
/**
 持续时间 (单位:秒钟) | durations
 */
@property (nonatomic,assign) NSInteger durations;
/**
 是否存储 | is save
 */
@property (nonatomic,assign) BOOL isSave;
/**
 平均心率 | avg heart rate
 */
@property (nonatomic,assign) NSInteger avgHrValue;
/**
 最大心率 | max heart rate
 */
@property (nonatomic,assign) NSInteger maxHrValue;
//======================= v2数据 =============================
/**
 脂肪燃烧时长 (分钟) | burn fat mins (mins)
 */
@property (nonatomic,assign) NSInteger burnFatMins;
/**
 有氧锻炼时长(分钟) | cardiopulmonary exercise mins
 */
@property (nonatomic,assign) NSInteger aerobicMins;
/**
 极限锻炼时长(分钟) | limit exercise mins
 */
@property (nonatomic,assign) NSInteger limitMins;

//======================= v3数据 =============================
/**
 热身锻炼时长(秒钟) | warm up exercise second
 */
@property (nonatomic,assign) NSInteger warmUpSecond;
/**
 无氧锻炼时长(秒钟) | anaeroic exercise second
 */
@property (nonatomic,assign) NSInteger anaeroicSecond;
/**
 燃脂锻炼时长(秒钟) | anaeroic exercise second
 */
@property (nonatomic,assign) NSInteger fatBurnSecond;
/**
 有氧锻炼时长(秒钟) | anaeroic exercise second
 */
@property (nonatomic,assign) NSInteger aerobicSecond;
/**
 极限锻炼时长(秒钟) | anaeroic exercise second
 */
@property (nonatomic,assign) NSInteger limitSecond;
/**
 热身运动值
 */
@property (nonatomic,assign) NSInteger warmUpValue;
/**
 脂肪燃烧运动值
 */
@property (nonatomic,assign) NSInteger burnFatValue;
/**
 有氧运动值
 */
@property (nonatomic,assign) NSInteger aerobicValue;
/**
 极限运动值
 */
@property (nonatomic,assign) NSInteger limitValue;
/**
 无氧运动值
 */
@property (nonatomic,assign) NSInteger anaerobicValue;
/**
 平均速度 km/h
 */
@property (nonatomic,assign) NSInteger avgSpeed;
/**
 最大速度 km/h
 */
@property (nonatomic,assign) NSInteger maxSpeed;
/**
 平均步频
 */
@property (nonatomic,assign) NSInteger avgStepFrequency;
/**
 最大步频
 */
@property (nonatomic,assign) NSInteger maxStepFrequency;
/**
 平均步幅
 */
@property (nonatomic,assign) NSInteger avgStepStride;
/**
 最大步幅
 */
@property (nonatomic,assign) NSInteger maxStepStride;
/**
 平均公里配速
 */
@property (nonatomic,assign) NSInteger kmSpeed;
/**
 最快公里配速
 */
@property (nonatomic,assign) NSInteger fastKmSpeed;
/**
 公里配速个数
 */
@property (nonatomic,assign) NSInteger kmSpeedCount;
/**
 公里配速集合
 */
@property (nonatomic,copy) NSArray<NSNumber *> * kmSpeeds;
/**
 英里配速 个数
 */
@property (nonatomic,assign) NSInteger mileCount;
/**
 实时配速 个数
 */
@property (nonatomic,assign) NSInteger realSpeedCount;
/**
 实时配速数组  传过来的是 s 钟  每5S算一次
 */
@property (nonatomic,assign) NSInteger paceSpeedCount;
/**
 英里配速集合
 */
@property (nonatomic,copy) NSArray<NSNumber *> * mileSpeeds;
/**
 步频个数
 */
@property (nonatomic,assign) NSInteger stepsFrequencyCount;
/**
 步频集合
 */
@property (nonatomic,copy) NSArray<NSNumber *> * stepsFrequencys;

/**
 实时配速集合
 */
@property (nonatomic,copy) NSArray<NSNumber *> * realSpeeds;

/**
 实时配速数组  传过来的是 s 钟  每5S算一次
 */
@property (nonatomic,copy) NSArray<NSNumber *> * paceSpeeds;

/**
 当前心率 | current heart rate
 */
@property (nonatomic,assign) NSInteger curHrValue;
/**
 心率间隔 | heart rate interval
 */
@property (nonatomic,assign) NSInteger intervalSecond;
/**
 序列号 | heart rate value serial
 */
@property (nonatomic,assign) NSInteger hrValueSerial;
/**
 心率个数
 */
@property (nonatomic,assign) NSInteger heartRateCount;
/**
 心率数据 | heart rate data
 */
@property (nonatomic,copy) NSArray<NSNumber *> * hrValues;
/**
 * 信号强弱  0: 表示信号弱， 1: 表示信号强
 * Signal strength 0: means signal is weak, 1: means signal is strong
 */
@property (nonatomic,assign) NSInteger signalFlag;
/**
 * app计算显示实时速度 单位km/h 100倍 15秒一个记录
 * App calculates and displays real-time speed km/h 100 times
 */
@property (nonatomic,assign) NSInteger realTimeSpeed;
/**
 * app计算显示实时配速 单位 s
 * App calculates and displays real-time pace unit second
 */
@property (nonatomic,assign) NSInteger realTimePace;
/**
 * 0x00 : 混合泳; 0x01 : 自由泳; 0x02 : 蛙泳; 0x03 : 仰泳; 0x04 : 蝶泳;
 * 0x00: medley; 0x01: freestyle; 0x02: breaststroke; 0x03: backstroke; 0x04: butterfly stroke;
 */
@property (nonatomic,assign) NSInteger swimPosture;
/**
 数据版本
 */
@property (nonatomic,assign) NSInteger dataVersion;
/**
 最大摄氧量；  单位：毫升/公斤/分钟； 范围  0-80
 */
@property (nonatomic,assign) NSInteger vo2Max;
/**
 无氧训练效果；  单位：无   范围 1.0 ~ 5.0 （*10倍）
 */
@property (nonatomic,assign) NSInteger anaerobicTrainingEffect;
/**
 有氧训练效果；  单位：无   范围 1.0 ~ 5.0 （*10倍）
 */
@property (nonatomic,assign) NSInteger trainingEffect;
/**
 本次动作训练个数
 */
@property (nonatomic,assign) NSInteger actionDataCount;
/**
 课程内运动热量  单位千卡
 */
@property (nonatomic,assign) NSInteger inClassCalories;
/**
 动作完成率 0—100
 */
@property (nonatomic,assign) NSInteger completionRate;
/**
 心率控制率  0—100
 */
@property (nonatomic,assign) NSInteger hrCompletionRate;
/**
 恢复时长：单位小时(app收到该数据之后，每过一小时需要自减一)
 */
@property (nonatomic,assign) NSInteger recoverTime;
/**
 摄氧量等级  0x01:低等   0x02:业余   0x03:一般  0x04：平均    0x05：良好  0x06：优秀   0x07：专业
 */
@property (nonatomic,assign) NSInteger grade;
/**
 3d距离 单位m
 */
@property (nonatomic,assign) NSInteger distance3d;
/**
 平均3d速度 单位km/h，PS：app收到需要 除于100，保存2位小数点。
 */
@property (nonatomic,assign) NSInteger avg3dSpeed;
/**
 平均垂直速度 单位m/h，PS：app收到需要 除于100，保存2位小数点。
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
 海拔高度数据 30s一组值 单位米 范围-500~9000 最大保存12小时
 */
@property (nonatomic,strong) NSArray<NSNumber *> * altitudeItems;

/**
 平均海拔高度 单位米 -500 ~ 9000
 */
@property (nonatomic,assign) NSInteger avgAltitude;

/**
 动作完成内容
 type : 动作类型  1快走；2慢跑; 3中速跑；4快跑
 heart_con_value : 每个动作心率控制
 time : 动作完成时间 单位秒
 goal_time ：动作目标时间
 */
@property (nonatomic,strong) NSMutableArray<NSDictionary *> * actionData;

/**
 训练的课程日期偏移 从0开始
 */
@property (nonatomic,assign) NSInteger trainingOffset;

/**
 计划类型：
 0x01：跑步计划3km ，0x02：跑步计划5km ，
 0x03：跑步计划10km ，0x04：半程马拉松训练（二期） ，0x05：马拉松训练（二期）
 */
@property (nonatomic,assign) NSInteger planType;

/**
 GPS状态 0:无效 1:开启 2:未开启(未开启时展示`距离` 开启则展示`3D距离`)
 功能表： __IDO_FUNCTABLE__.funcTable36Model.supportExchangeActivityGetGpsStatus
 */
@property (nonatomic,assign) NSInteger gpsStatus;


//--------------- version=0x50新增字段 ---------------
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
@property (nonatomic,strong) NSMutableArray<NSNumber *> * runningPowerItems;
/**
 实时体力RTPE(real-time physical exertion)详情 0-100百分比
 */
@property (nonatomic,strong) NSMutableArray<NSNumber *> * rtpeItems;
/**
 实时摄氧量RTOC(real-time oxygen consumption)详情 0-9999 单位ml/min
 */
@property (nonatomic,strong) NSMutableArray<NSNumber *> * rtocItems;
/**
 跳绳详情
 每次连跳次数:  rope_skip_count;
 时长 单位秒: duration;
 */
@property (nonatomic,strong) NSMutableArray<NSDictionary *> * ropeItems;

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
 最小步幅 单位厘米
 Minimum stride in centimeters
 */
@property (nonatomic,assign) NSInteger minStepStride;

/**
 最小步频 步/分钟
 Minimum step rate/min
 */
@property (nonatomic,assign) NSInteger minStepFrequency;

/**
 最慢公里配速 s/km
 The slowest km speed is s/km
 */
@property (nonatomic,assign) NSInteger slowestKmPace;

@end

