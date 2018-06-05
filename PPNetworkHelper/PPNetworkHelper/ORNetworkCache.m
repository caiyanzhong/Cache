//
//  ORNetworkCache.m
//  MyShop
//
//  Created by MacBook Air on 2018/4/23.
//  Copyright © 2018年 YH. All rights reserved.
//

#import "ORNetworkCache.h"
#import "YYCache.h"

static NSString *const kORNetworkResponseCache = @"kORNetworkResponseCache";

@implementation ORNetworkCache
static YYCache *_dataCache;

+ (void)initialize {
    _dataCache = [YYCache cacheWithName:kORNetworkResponseCache];
}

+ (void)setHttpCache:(id)httpData URL:(NSString *)URL parameters:(NSDictionary *)parameters {
    NSString *cacheKey = [NSString stringWithFormat:@"%@/%@",URL,parameters];
    //异步缓存,不会阻塞主线程
    [_dataCache setObject:httpData forKey:cacheKey withBlock:nil];
}

+ (id)httpCacheForURL:(NSString *)URL parameters:(NSDictionary *)parameters {
    NSString *cacheKey = [NSString stringWithFormat:@"%@/%@",URL,parameters];
    return [_dataCache objectForKey:cacheKey];
}

+ (NSInteger)getAllHttpCacheSize {
    return [_dataCache.diskCache totalCost];
}

+ (void)removeAllHttpCache {
    [_dataCache.diskCache removeAllObjects];
}

+ (NSString *)cacheKeyWithURL:(NSString *)URL parameters:(NSDictionary *)parameters {
    if(!parameters || parameters.count == 0){return URL;};
    // 将参数字典转换成字符串
    NSData *stringData = [NSJSONSerialization dataWithJSONObject:parameters options:0 error:nil];
    NSString *paraString = [[NSString alloc] initWithData:stringData encoding:NSUTF8StringEncoding];    
    return [NSString stringWithFormat:@"%@%@",URL,paraString];
}


@end

