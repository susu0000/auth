//
//  WMWeiXinManager.h
//
//  Created by zwm on 15/5/14.
//  Copyright (c) 2015年 zwm. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WMAuthManager.h"

#define WXAppKey    @"wx37496a0e9d616484"
#define WXSecret    @"c454b6604b65cf4bb852fc4ac27cb50f"

// SystemConfiguration.framework,libz.dylib,libsqlite3.0.dylib

@interface WMWeiXinManager : NSObject

+ (BOOL)isAppInstalled;

+ (void)registerApp;

+ (BOOL)handleOpenURL:(NSURL *)url;

+ (void)sendAuthWithBlock:(WMAuthBlock)result
             withUserInfo:(WMUserInfoBlock)block
           withController:(UIViewController *)viewController;

+ (BOOL)isUserInfo;
+ (NSString *)getUserName;
+ (NSString *)getUserAvatar;

///  分享到微信好友
///  @param title       标题，长度不能超过512字节
///  @param description 简要描述，长度不能超过1K
///  @param image       配一张缩略图，大小不能超过32K
///  @param url         指向链接，不能为空且长度不能超过10K
///  @param result      回调是否成功，error为nil成功，失败error.domain原因
+ (void)shareFirend:(NSString *)title
        description:(NSString *)description
              thumb:(UIImage *)image
                url:(NSString *)url
             result:(WMShareBlock)result;
/// 分享到微信朋友圈，参数同上
+ (void)shareFirends:(NSString *)title
               thumb:(UIImage *)image
                 url:(NSString *)url
              result:(WMShareBlock)result;

@end
