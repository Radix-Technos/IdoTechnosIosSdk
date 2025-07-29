//
//  IDOScManager.h
//  IDOBlueProtocol
//
//  Created by chenhuili on 2023/10/19.
//  Copyright © 2023 何东阳. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IDOScManager : NSObject
/**
 * 制作思澈表盘文件
 * filePath:  传入素材路径, 制作成功后文件的路径为传入的filePath
 * @return 错误码，0成功 非0失败 -1: 没有控件 -2: json文件加载失败
 */

+ (int)getMakeSiFliWatchDialWithFilePath:(NSString *)filePath;


 /**
* @brief 获取思澈表盘(.watch)文件占用空间大小，计算规则：
* nor方案：对表盘所有文件以4096向上取整  -  98平台对应的项目，IDW27,205G Pro,IDW28,IDS05，DR03等
* nand方案：对表盘所有文件以2048向上取整 -  99平台对应的项目，GTX12,GTX13,GTR1,TIT21
* @param filePath .watch文件路径，包含文件名
* @param platform 平台类型，目前有98(nor)，99(nand)平台
* @return size 文件占用磁盘的实际大小，-1:失败，文件路径访问失败，-2:失败，申请内存失败，-3:失败，读取文件失败，-4:失败，输入平台类型不支持
*/
+ (NSUInteger)getSifliWatchDialSizeWithPath:(NSString *)filePath platform:(int)platform;


@end

NS_ASSUME_NONNULL_END
