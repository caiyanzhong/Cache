//
//  ORMoneyLabel.h
//  MyShop
//
//  Created by MacBook Air on 2018/4/24.
//  Copyright © 2018年 YH. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ORMethods : NSObject


//验证手机号码
+ (BOOL)valiMobile:(NSString *)mobile;

/**
 *  计算上次日期距离现在多久
 *
 *  @param lastTime    上次日期(需要和格式对应)
 *  @param currentTime 最近日期(需要和格式对应)
 *
 *  @return xx分钟前、xx小时前、xx天前
 */
+ (NSString *)timeIntervalFromLastTime:(NSDate *)lastTime ToCurrentTime:(NSDate *)currentTime;

//将颜色转成图片

//获取当前时间戳(以秒为单位)
+(NSString *)getNowTimeTimestamp;

//md5加密
+(NSString *)MD5ForLower32Bate:(NSString *)str;

//返回6位数字
+(NSString *)return6Number;

//生成sign
+ (NSString *)returnSignMethod:(NSString *)method Rand:(NSString *)rand Time:(NSString *)time;




@end
