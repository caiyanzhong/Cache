//
//  ORCacheURLProtocol.h
//  ORNetCache
//
//  Created by MacBook Air on 2018/4/23.
//  Copyright © 2018年 YH. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ORCacheURLProtocol : NSURLProtocol<NSURLSessionDataDelegate>


@property (readwrite, nonatomic, strong) NSURLSessionConfiguration *config;//config是全局的，所有的网络请求都用这个config

@property (readwrite, nonatomic, assign) NSInteger updateInterval;//相同的url地址请求，相隔大于等于updateInterval才会发出后台更新的网络请求，小于的话不发出请求。

+ (void)startListeningNetWorking;
+ (void)cancelListeningNetWorking;

+ (void)setConfig:(NSURLSessionConfiguration *)config;//config是全局的，所有的网络请求都用这个config，参见NSURLSession使用的NSURLSessionConfiguration
+ (void)setUpdateInterval:(NSInteger)updateInterval;//相同的url地址请求，相隔大于等于updateInterval才会发出后台更新的网络请求，小于的话不发出请求。默认是3600秒，1个小时
+ (void)clearUrlDict;//收到内存警告的时候可以调用这个方法清空内存中的url记录
@end
