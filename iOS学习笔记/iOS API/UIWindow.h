//
//  UIWindow.h
//  UIKit
//
//  Copyright (c) 2005-2017 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIView.h>
#import <UIKit/UIApplication.h>
#import <UIKit/UIKitDefines.h>
//http://www.jianshu.com/p/2d4dcf7d97eb
//这篇关于UIWindow的文章是在iOS7版本时研究发布的，一个APP同时创建多个window本就不被苹果所支持，目前iOS9已经完全不支持不设置rootViewController的window存在，该文中的demo已不成立。

NS_ASSUME_NONNULL_BEGIN

//UIWindow在显示的时候会根据UIWindowLevel进行排序的，即Level高的将排在所有Level比他低的层级的前面。
typedef CGFloat UIWindowLevel;

@class UIEvent, UIScreen, NSUndoManager, UIViewController;

//http://www.cnblogs.com/smileEvday/archive/2012/03/27/2420362.html
//UIWindow是一种特殊的UIView，通常在一个程序中只会有一个UIWindow，但可以手动创建多个UIWindow，同时加到程序里面。
NS_CLASS_AVAILABLE_IOS(2_0) @interface UIWindow : UIView //UIWindow 就是一种特殊的UIView

//screen是window的屏幕,默认是 [UIScreen mainScreen] ,不能更改，否则没有界面
@property(nonatomic,strong) UIScreen *screen NS_AVAILABLE_IOS(3_2);  // default is [UIScreen mainScreen]. changing the screen may be an expensive operation and should not be done in performance-sensitive code

@property(nonatomic) UIWindowLevel windowLevel;                   // default = 0.0

//keyWindow只有一个，当有多个时，默认最后设置（makeKeyWindow、makeKeyAndVisible）的那个为keyWindow
@property(nonatomic,readonly,getter=isKeyWindow) BOOL keyWindow;

//不可直接调用，当需要用时，需要继承子类，然后实现这两个方法，
//所以这就提出了一种编程思想，能继承子类的，尽量继承自类，这样才能有更多的自定义空间
//貌似，UIWindow实现了这个方法，也没有用，所以还是得子类实现
- (void)becomeKeyWindow;                               // override point for subclass. Do not call directly
- (void)resignKeyWindow;                               // override point for subclass. Do not call directly

- (void)makeKeyWindow;// 让当前UIWindow变成keyWindow（主窗口）

- (void)makeKeyAndVisible;                             // convenience. most apps call this to show the main window and also make it key. otherwise use view hidden property
//让当前UIWindow变成keyWindow，并显示出来


//动将rootViewController的view添加到UIWindow中，负责管理rootViewController的生命周期
@property(nullable, nonatomic,strong) UIViewController *rootViewController NS_AVAILABLE_IOS(4_0);  // default is nil

//过UIApplication 调用来分发任务给window 中的视图
- (void)sendEvent:(UIEvent *)event;                    // called by UIApplication to dispatch events to views inside the window

//// 把该window中的一个坐标转换成在目标window中时的坐标值
- (CGPoint)convertPoint:(CGPoint)point toWindow:(nullable UIWindow *)window;    // can be used to convert to another window

//// 把目标window中的一个坐标转换成在该window中时的坐标值
- (CGPoint)convertPoint:(CGPoint)point fromWindow:(nullable UIWindow *)window;  // pass in nil to mean screen

//// 把该window中的一个矩阵转换成在目标window中时的矩阵值
- (CGRect)convertRect:(CGRect)rect toWindow:(nullable UIWindow *)window;

//把目标window中的一个矩阵转换成在该window中时的矩阵值
- (CGRect)convertRect:(CGRect)rect fromWindow:(nullable UIWindow *)window;

@end

//这样印证了他们级别的高低顺序从小到大为Normal < StatusBar < Alert
/*
#ifdef __cplusplus
#define UIKIT_EXTERN        extern "C" __attribute__((visibility ("default")))
#else
#define UIKIT_EXTERN            extern __attribute__((visibility ("default")))
#endif
*/

UIKIT_EXTERN const UIWindowLevel UIWindowLevelNormal; //0
UIKIT_EXTERN const UIWindowLevel UIWindowLevelAlert;//2000
UIKIT_EXTERN const UIWindowLevel UIWindowLevelStatusBar __TVOS_PROHIBITED;//1000

//各种通知
UIKIT_EXTERN NSNotificationName const UIWindowDidBecomeVisibleNotification; // nil
UIKIT_EXTERN NSNotificationName const UIWindowDidBecomeHiddenNotification;  // nil
UIKIT_EXTERN NSNotificationName const UIWindowDidBecomeKeyNotification;     // nil
UIKIT_EXTERN NSNotificationName const UIWindowDidResignKeyNotification;     // nil

//http://blog.csdn.net/iosfengguibin/article/details/53140241
//正确，注册、移除通知的地方


// Each notification includes a nil object and a userInfo dictionary containing the
// begining and ending keyboard frame in screen coordinates. Use the various UIView and
// UIWindow convertRect facilities to get the frame in the desired coordinate system.
// Animation key/value pairs are only available for the "will" family of notification.
UIKIT_EXTERN NSNotificationName const UIKeyboardWillShowNotification __TVOS_PROHIBITED; //常见的通知
UIKIT_EXTERN NSNotificationName const UIKeyboardDidShowNotification __TVOS_PROHIBITED;
UIKIT_EXTERN NSNotificationName const UIKeyboardWillHideNotification __TVOS_PROHIBITED;
UIKIT_EXTERN NSNotificationName const UIKeyboardDidHideNotification __TVOS_PROHIBITED;

//首先注册通知
//然后在通知selector里面，获取参数，通过以下的一些key来获取
//最后，按需修改

//这些都是key，获取userInfo里面的值
UIKIT_EXTERN NSString *const UIKeyboardFrameBeginUserInfoKey        NS_AVAILABLE_IOS(3_2) __TVOS_PROHIBITED; // NSValue of CGRect////键盘动画起始时的frame
UIKIT_EXTERN NSString *const UIKeyboardFrameEndUserInfoKey          NS_AVAILABLE_IOS(3_2) __TVOS_PROHIBITED; // NSValue of CGRect

//动画持续时间
UIKIT_EXTERN NSString *const UIKeyboardAnimationDurationUserInfoKey NS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED; // NSNumber of double

//UIViewAnimationCurve，是卷页效果,//动画曲线类型
UIKIT_EXTERN NSString *const UIKeyboardAnimationCurveUserInfoKey    NS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED; // NSNumber of NSUInteger (UIViewAnimationCurve)

//键盘是否显示，bool类型，1 show，2 hide
UIKIT_EXTERN NSString *const UIKeyboardIsLocalUserInfoKey           NS_AVAILABLE_IOS(9_0) __TVOS_PROHIBITED; // NSNumber of BOOL

// Like the standard keyboard notifications above, these additional notifications include
// a nil object and begin/end frames of the keyboard in screen coordinates in the userInfo dictionary.
UIKIT_EXTERN NSNotificationName const UIKeyboardWillChangeFrameNotification  NS_AVAILABLE_IOS(5_0) __TVOS_PROHIBITED; //这个通知，比UIKeyboardWillShowNotification要早
UIKIT_EXTERN NSNotificationName const UIKeyboardDidChangeFrameNotification   NS_AVAILABLE_IOS(5_0) __TVOS_PROHIBITED;

/*
 superseded
 adj.
 [医]被代替的，废弃的
 v.
 取代，接替( supersede的过去式和过去分词 )
 
 */
// These keys are superseded by UIKeyboardFrameBeginUserInfoKey and UIKeyboardFrameEndUserInfoKey.
UIKIT_EXTERN NSString *const UIKeyboardCenterBeginUserInfoKey   NS_DEPRECATED_IOS(2_0, 3_2) __TVOS_PROHIBITED; //deprecated////键盘动画起始时的中心点
UIKIT_EXTERN NSString *const UIKeyboardCenterEndUserInfoKey     NS_DEPRECATED_IOS(2_0, 3_2) __TVOS_PROHIBITED;////键盘动画结束时的中心点
UIKIT_EXTERN NSString *const UIKeyboardBoundsUserInfoKey        NS_DEPRECATED_IOS(2_0, 3_2) __TVOS_PROHIBITED;///键盘的bounds

NS_ASSUME_NONNULL_END
//将要显示打印出来的信息,
/*
 UIKeyboardAnimationCurveUserInfoKey = 7;
 UIKeyboardAnimationDurationUserInfoKey = "0.25";
 UIKeyboardBoundsUserInfoKey = "NSRect: {{0, 0}, {320, 253}}";
 UIKeyboardCenterBeginUserInfoKey = "NSPoint: {160, 568}";//568 iPhone SE的高度
 UIKeyboardCenterEndUserInfoKey = "NSPoint: {160, 441.5}";///
 UIKeyboardFrameBeginUserInfoKey = "NSRect: {{0, 568}, {320, 0}}";/键盘动画起始时的frame
 UIKeyboardFrameEndUserInfoKey = "NSRect: {{0, 315}, {320, 253}}";//键盘动画结束时的frame
 UIKeyboardIsLocalUserInfoKey = 1;
 */
