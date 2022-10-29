//
//  GSWallet.h
//  GSWallet
//
//  Copyright © 2022 game.space. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <GSWallet/GSWalletObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSWallet : NSObject

+ (void)registerApp:(NSString *)appId;

+ (void)registerApp:(NSString *)appId network:(GSWNetwork)network;

+ (void)registerApp:(NSString *)appId channel:(nullable NSString *)channel;

+ (void)registerApp:(NSString *)appId channel:(nullable NSString *)channel network:(GSWNetwork)network;

+ (BOOL)handleOpenURL:(NSURL *)url delegate:(id<GSWalletDelegate>)delegate;

+ (BOOL)isAppInstalled;

+ (NSString *)getAppInstallURL;

+ (void)sendRequest:(GSBaseRequest *)request completion:(void (^ __nullable)(NSError *error))completion;

+ (BOOL)openApp:(NSString *)path;

+ (NSString *)getVersion;

+ (void)enableDebug:(BOOL)enabled;

+ (void)openWallet:(NSDictionary *)options
              from:(UIViewController *)viewController
          delegate:(id<GSWalletDelegate>)delegate;

+ (void)openWallet:(NSDictionary *)options
              from:(UIViewController *)viewController
           request:(GSBaseRequest *)request
          delegate:(id<GSWalletDelegate>)delegate
        completion:(void (^ __nullable)(NSError *error))completion;

+ (void)closeWallet;

+ (void)logoutWallet;

@end

NS_ASSUME_NONNULL_END
