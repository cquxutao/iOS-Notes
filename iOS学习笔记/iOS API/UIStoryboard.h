//
//  UIStoryboard.h
//  UIKit
//
//  Copyright 2011-2017 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
//http://www.samirchen.com/view-controller-lifecycle-in-ios/
/*
 App 启动时，首先自动加载其 rootViewController（self.window.rootViewController），这个过程是自动调用 instantiateInitialViewController 来完成的。此后 Storyboard 中 View Controller 之间的跳转是通过 segue，navigation 等机制来实现的。通常我们在 App 启动后，想要初始化 Storyboard 中其他的 View Controller 时，可以调用 instantiateViewControllerWithIdentifier:，比如：
 
 YourViewController *vc = [self.storyboard instantiateViewControllerWithIdentifier:@"Your_VC_Storyboard_ID"];
 initWithNibName:bundle: 方法是不会被调用的，不需要我们关注它。加载过程中，会去访问 View Controller 的 view 属性，这时会自动调用 loadView，在这种情况下我们不应该重载 loadView，所以也不需要我们关注它。
 */
@class UIViewController;

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE_IOS(5_0) @interface UIStoryboard : NSObject {
}

+ (UIStoryboard *)storyboardWithName:(NSString *)name bundle:(nullable NSBundle *)storyboardBundleOrNil;

- (nullable __kindof UIViewController *)instantiateInitialViewController;
- (__kindof UIViewController *)instantiateViewControllerWithIdentifier:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
