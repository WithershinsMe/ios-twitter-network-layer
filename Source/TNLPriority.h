//
//  TNLPriority.h
//  TwitterNetworkLayer
//
//  Created on 7/17/14.
//  Copyright (c) 2014 Twitter. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 TNLPriority

 A general purpose enum to represent priority.  Primarily used by `TNLRequestOperation`.
 */
typedef NS_ENUM(NSInteger, TNLPriority) {
    /** Very Low */
    TNLPriorityVeryLow = -2,
    /** Low */
    TNLPriorityLow = -1,
    /** Normal */
    TNLPriorityNormal = 0,
    /** High */
    TNLPriorityHigh = 1,
    /** Very High */
    TNLPriorityVeryHigh = 2
};

/**
 TNLFeaturePriority

 A mapping from app features to priority values
 */
typedef NS_ENUM(NSInteger, TNLFeaturePriority) {
    TNLFeaturePriorityPolling = TNLPriorityVeryLow,
    TNLFeaturePriorityPrefetching = TNLPriorityVeryLow,
    TNLFeaturePriorityContentImage = TNLPriorityLow,
    TNLFeaturePrioritySpecificImage = TNLPriorityNormal,
    TNLFeaturePriorityCurrentViewLoad = TNLPriorityHigh,
    TNLFeaturePriorityUserInitiated = TNLPriorityVeryHigh,
};

// Conversion functions

FOUNDATION_EXTERN TNLPriority TNLConvertQueuePriorityToTNLPriority(NSOperationQueuePriority pri) __attribute__((const));
FOUNDATION_EXTERN TNLPriority TNLConvertURLSessionTaskPriorityToTNLPriority(float pri) __attribute__((const));
FOUNDATION_EXTERN TNLPriority TNLConvertQualityOfServiceToTNLPriority(NSQualityOfService qos) __attribute__((const));

FOUNDATION_EXTERN NSOperationQueuePriority TNLConvertTNLPriorityToQueuePriority(TNLPriority pri) __attribute__((const));
FOUNDATION_EXTERN float TNLConvertTNLPriorityToURLSessionTaskPriority(TNLPriority pri) __attribute__((const));
FOUNDATION_EXTERN NSQualityOfService TNLConvertTNLPriorityToQualityOfService(TNLPriority pri) __attribute__((const));

NS_ASSUME_NONNULL_END
