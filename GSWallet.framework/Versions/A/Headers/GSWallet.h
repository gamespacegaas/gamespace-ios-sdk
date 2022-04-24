//
//  GSWallet.h
//  GSWallet
//
//  Copyright © 2022 game.space. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GSWallet/GSWalletObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSWallet : NSObject

+ (void)registerApp:(NSString *)appId;

+ (BOOL)handleOpenURL:(NSURL *)url delegate:(id<GSWalletDelegate>)delegate;

+ (BOOL)isAppInstalled;

+ (NSString *)getAppInstallURL;

+ (void)sendRequest:(GSBaseRequest *)request completion:(void (^ __nullable)(NSError *error))completion;

+ (BOOL)openApp:(NSString *)path;

+ (NSString *)getVersion;

+ (void)enableDebug:(BOOL)enabled;

@end

NS_ASSUME_NONNULL_END
