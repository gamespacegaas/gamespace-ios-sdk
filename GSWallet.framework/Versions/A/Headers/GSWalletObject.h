//
//  GSWalletObject.h
//  GSWallet
//
//  Copyright © 2022 game.space. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum
{
    GSWSuccess,
    GSWErrorCodeCommon          = -1,
    GSWErrorCodeUserCancel      = -2,
    GSWErrorCodeSentFail        = -3,
    GSWErrorCodeAuthDeny        = -4,
    GSWErrorCodeUnsupport       = -5,
    GSWErrorCodeParamMissing    = -900,
    GSWErrorCodeParamError      = -901,
    GSWErrorCodeAppNotInstall   = -902,
} GSWErrorCode;

typedef enum
{
    GSWRequestTypeAuth          = 1,
    GSWRequestTypePay,
    GSWRequestTypeOpenWebView
} GSWRequestType;

typedef enum
{
    GSWResponseTypeAuth         = 1,
    GSWResponseTypePay,
    GSWResponseTypeOpenWebView
} GSWResponseType;

@interface GSBaseRequest : NSObject

@property(nonatomic, assign) GSWRequestType type;
@property(nonatomic, copy) NSString *openId;

+ (instancetype)request;

- (NSString *)encode:(NSDictionary *)extra;

- (NSError *)validate;

@end

@interface GSBaseResponse : NSObject

@property(nonatomic, assign) GSWResponseType type;
@property(nonatomic, assign) GSWErrorCode errorCode;
@property(nonatomic, copy) NSString *errorMessage;

+ (instancetype)responseWithData:(NSDictionary *)data;
- (instancetype)initWithData:(NSDictionary *)data;

@end

@interface GSAuthRequest : GSBaseRequest

@property(nonatomic, copy) NSString *scope;
@property(nonatomic, copy) NSString *state;

@end

@interface GSAuthResponse : GSBaseResponse

@property(nonatomic, copy) NSString *code;
@property(nonatomic, copy) NSString *state;

@end

@interface GSPayRequest : GSBaseRequest

@property(nonatomic, copy) NSString *prepayId;
@property(nonatomic, copy) NSString *nonce;
@property(nonatomic, copy) NSString *sign;
@property(nonatomic, assign) NSUInteger timestamp;

@end

@interface GSPayResponse : GSBaseResponse

@property(nonatomic,copy) NSString *customId;
@property(nonatomic,copy) NSString *transactionId;

@end

@interface GSOpenWebViewRequest : GSBaseRequest

@property(nonatomic, copy) NSString *url;

@end

@interface GSOpenWebViewResponse : GSBaseResponse

@end

@protocol GSWalletDelegate <NSObject>

@optional

- (void)onWalletResponse:(GSBaseResponse *)response;

@end

NS_ASSUME_NONNULL_END
