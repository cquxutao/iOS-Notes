//
//  UIView.h
//  UIKit
//
//  Copyright (c) 2005-2017 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>
#import <UIKit/UIResponder.h>
#import <UIKit/UIInterface.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIAppearance.h>
#import <UIKit/UIDynamicBehavior.h>
#import <UIKit/NSLayoutConstraint.h>
#import <UIKit/UITraitCollection.h>
#import <UIKit/UIFocus.h>

NS_ASSUME_NONNULL_BEGIN

//UIViewAnimationCurve是卷页效果,翻译为动画曲线效果更好
//UIViewAnimationCurveEaseInOut,弹入弹出效果,启动和最后都快一些,中间时间慢一些
//UIViewAnimationCurveEaseIn是弹入效果,启动时快点后来慢点
typedef NS_ENUM(NSInteger, UIViewAnimationCurve) {
    UIViewAnimationCurveEaseInOut,         // slow at beginning and end 0
    UIViewAnimationCurveEaseIn,            // slow at beginning 1
    UIViewAnimationCurveEaseOut,           // slow at end 2
    UIViewAnimationCurveLinear, //3
};

//填充类型
typedef NS_ENUM(NSInteger, UIViewContentMode) {
    UIViewContentModeScaleToFill,
    UIViewContentModeScaleAspectFit,      // contents scaled to fit with fixed aspect. remainder is transparent
    UIViewContentModeScaleAspectFill,     // contents scaled to fill with fixed aspect. some portion of content may be clipped.
    UIViewContentModeRedraw,              // redraw on bounds change (calls -setNeedsDisplay)
    UIViewContentModeCenter,              // contents remain same size. positioned adjusted.
    UIViewContentModeTop,
    UIViewContentModeBottom,
    UIViewContentModeLeft,
    UIViewContentModeRight,
    UIViewContentModeTopLeft,
    UIViewContentModeTopRight,
    UIViewContentModeBottomLeft,
    UIViewContentModeBottomRight,
};

typedef NS_ENUM(NSInteger, UIViewAnimationTransition) {
    UIViewAnimationTransitionNone,
    UIViewAnimationTransitionFlipFromLeft,
    UIViewAnimationTransitionFlipFromRight,
    UIViewAnimationTransitionCurlUp,
    UIViewAnimationTransitionCurlDown,
};

typedef NS_OPTIONS(NSUInteger, UIViewAutoresizing) {
    UIViewAutoresizingNone                 = 0,
    UIViewAutoresizingFlexibleLeftMargin   = 1 << 0,
    UIViewAutoresizingFlexibleWidth        = 1 << 1,
    UIViewAutoresizingFlexibleRightMargin  = 1 << 2,
    UIViewAutoresizingFlexibleTopMargin    = 1 << 3,
    UIViewAutoresizingFlexibleHeight       = 1 << 4,
    UIViewAutoresizingFlexibleBottomMargin = 1 << 5
};

typedef NS_OPTIONS(NSUInteger, UIViewAnimationOptions) {
    UIViewAnimationOptionLayoutSubviews            = 1 <<  0,////提交动画的时候布局子控件，表示子控件将和父控件一同动画。
    UIViewAnimationOptionAllowUserInteraction      = 1 <<  1, // turn on user interaction while animating动画时允许用户交流，比如触摸
    UIViewAnimationOptionBeginFromCurrentState     = 1 <<  2, // start all views from current value, not initial value从当前状态开始动画
    UIViewAnimationOptionRepeat                    = 1 <<  3, // repeat animation indefinitely动画无限重复
    UIViewAnimationOptionAutoreverse               = 1 <<  4, // if repeat, run animation back and forth执行动画回路,前提是设置动画无限重复
    UIViewAnimationOptionOverrideInheritedDuration = 1 <<  5, // ignore nested duration忽略外层动画嵌套的执行时间
    UIViewAnimationOptionOverrideInheritedCurve    = 1 <<  6, // ignore nested curve忽略外层动画嵌套的时间变化曲线
    UIViewAnimationOptionAllowAnimatedContent      = 1 <<  7, // animate contents (applies to transitions only)通过改变属性和重绘实现动画效果，如果key没有提交动画将使用快照
    UIViewAnimationOptionShowHideTransitionViews   = 1 <<  8, // flip to/from hidden state instead of adding/removing
    UIViewAnimationOptionOverrideInheritedOptions  = 1 <<  9, // do not inherit any options or animation type
  
  // //时间函数曲线相关
    UIViewAnimationOptionCurveEaseInOut            = 0 << 16, // default
    UIViewAnimationOptionCurveEaseIn               = 1 << 16,
    UIViewAnimationOptionCurveEaseOut              = 2 << 16,
    UIViewAnimationOptionCurveLinear               = 3 << 16,
  
  //转场动画相关
  /*
   补充：关于最后一组转场动画它一般是用在这个方法中的：
   
   　　　　[UIView transitionFromView: toView: duration: options: completion:^(BOOL finished) {}];
   
   　该方法效果是插入一面视图移除一面视图，期间可以使用一些转场动画效果。
   */
    UIViewAnimationOptionTransitionNone            = 0 << 20, // default //无转场动画
    UIViewAnimationOptionTransitionFlipFromLeft    = 1 << 20,////转场从左翻转
    UIViewAnimationOptionTransitionFlipFromRight   = 2 << 20,////转场从右翻转
    UIViewAnimationOptionTransitionCurlUp          = 3 << 20,// //上卷转场
    UIViewAnimationOptionTransitionCurlDown        = 4 << 20,// //下卷转场
    UIViewAnimationOptionTransitionCrossDissolve   = 5 << 20,////转场交叉消失
    UIViewAnimationOptionTransitionFlipFromTop     = 6 << 20,// //转场从上翻转
    UIViewAnimationOptionTransitionFlipFromBottom  = 7 << 20,//转场从下翻转
  
  //这几个是什么玩意？？？
    UIViewAnimationOptionPreferredFramesPerSecondDefault     = 0 << 24,
    UIViewAnimationOptionPreferredFramesPerSecond60          = 3 << 24,
    UIViewAnimationOptionPreferredFramesPerSecond30          = 7 << 24,
    
} NS_ENUM_AVAILABLE_IOS(4_0);

typedef NS_OPTIONS(NSUInteger, UIViewKeyframeAnimationOptions) {
    UIViewKeyframeAnimationOptionLayoutSubviews            = UIViewAnimationOptionLayoutSubviews,
    UIViewKeyframeAnimationOptionAllowUserInteraction      = UIViewAnimationOptionAllowUserInteraction, // turn on user interaction while animating
    UIViewKeyframeAnimationOptionBeginFromCurrentState     = UIViewAnimationOptionBeginFromCurrentState, // start all views from current value, not initial value
    UIViewKeyframeAnimationOptionRepeat                    = UIViewAnimationOptionRepeat, // repeat animation indefinitely
    UIViewKeyframeAnimationOptionAutoreverse               = UIViewAnimationOptionAutoreverse, // if repeat, run animation back and forth
    UIViewKeyframeAnimationOptionOverrideInheritedDuration = UIViewAnimationOptionOverrideInheritedDuration, // ignore nested duration
    UIViewKeyframeAnimationOptionOverrideInheritedOptions  = UIViewAnimationOptionOverrideInheritedOptions, // do not inherit any options or animation type
    
    UIViewKeyframeAnimationOptionCalculationModeLinear     = 0 << 10, // default
    UIViewKeyframeAnimationOptionCalculationModeDiscrete   = 1 << 10,
    UIViewKeyframeAnimationOptionCalculationModePaced      = 2 << 10,
    UIViewKeyframeAnimationOptionCalculationModeCubic      = 3 << 10,
    UIViewKeyframeAnimationOptionCalculationModeCubicPaced = 4 << 10
} NS_ENUM_AVAILABLE_IOS(7_0);
    
typedef NS_ENUM(NSUInteger, UISystemAnimation) {
    UISystemAnimationDelete,    // removes the views from the hierarchy when complete
} NS_ENUM_AVAILABLE_IOS(7_0);

typedef NS_ENUM(NSInteger, UIViewTintAdjustmentMode) {
    UIViewTintAdjustmentModeAutomatic,
    
    UIViewTintAdjustmentModeNormal,
    UIViewTintAdjustmentModeDimmed,
} NS_ENUM_AVAILABLE_IOS(7_0);

typedef NS_ENUM(NSInteger, UISemanticContentAttribute) {
    UISemanticContentAttributeUnspecified = 0,
    UISemanticContentAttributePlayback, // for playback controls such as Play/RW/FF buttons and playhead scrubbers
    UISemanticContentAttributeSpatial, // for controls that result in some sort of directional change in the UI, e.g. a segmented control for text alignment or a D-pad in a game
    UISemanticContentAttributeForceLeftToRight,
    UISemanticContentAttributeForceRightToLeft
} NS_ENUM_AVAILABLE_IOS(9_0);

@protocol UICoordinateSpace <NSObject>

- (CGPoint)convertPoint:(CGPoint)point toCoordinateSpace:(id <UICoordinateSpace>)coordinateSpace NS_AVAILABLE_IOS(8_0);
- (CGPoint)convertPoint:(CGPoint)point fromCoordinateSpace:(id <UICoordinateSpace>)coordinateSpace NS_AVAILABLE_IOS(8_0);
- (CGRect)convertRect:(CGRect)rect toCoordinateSpace:(id <UICoordinateSpace>)coordinateSpace NS_AVAILABLE_IOS(8_0);
- (CGRect)convertRect:(CGRect)rect fromCoordinateSpace:(id <UICoordinateSpace>)coordinateSpace NS_AVAILABLE_IOS(8_0);

@property (readonly, nonatomic) CGRect bounds NS_AVAILABLE_IOS(8_0);

@end

@class UIBezierPath, UIEvent, UIWindow, UIViewController, UIColor, UIGestureRecognizer, UIMotionEffect, CALayer, UILayoutGuide;

NS_CLASS_AVAILABLE_IOS(2_0) @interface UIView : UIResponder <NSCoding, UIAppearance, UIAppearanceContainer, UIDynamicItem, UITraitEnvironment, UICoordinateSpace, UIFocusItem, CALayerDelegate>

#if UIKIT_DEFINE_AS_PROPERTIES
@property(class, nonatomic, readonly) Class layerClass;                        // default is [CALayer class]. Used when creating the underlying layer for the view.
#else
+ (Class)layerClass;                        // default is [CALayer class]. Used when creating the underlying layer for the view.
#endif

//http://www.jianshu.com/p/82a3b9a96d29
//初始化方法
//initWithCoder：使用文件加载的对象调用（如从xib或stroyboard中创建）
//initWithFrame：使用代码加载的对象调用（使用纯代码创建）
//注意：所以为了同时兼顾从文件和从代码解析的对象初始化，要同时在initWithCoder: 和 initWithFrame: 中进行初始化

- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;//使用代码加载的对象调用（使用纯代码创建）
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;//initWithCoder 这个是我们用IB初始View来调用的。//initWithCoder: 只要对象是从文件解析来的，就会调用//initWithCoder：使用文件加载的对象调用（如从xib或stroyboard中创建）
//注意：所以为了同时兼顾从文件和从代码解析的对象初始化，要同时在initWithCoder: 和 initWithFrame: 中进行初始化

@property(nonatomic,getter=isUserInteractionEnabled) BOOL userInteractionEnabled;  // default is YES. if set to NO, user events (touch, keys) are ignored and removed from the event queue.
@property(nonatomic)                                 NSInteger tag;                // default is 0
@property(nonatomic,readonly,strong)                 CALayer  *layer;              // returns view's layer. Will always return a non-nil value. view is layer's delegate(每个view都有一个layer，同时view是layer的代理)


#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic,readonly) BOOL canBecomeFocused NS_AVAILABLE_IOS(9_0); // NO by default
#else
- (BOOL)canBecomeFocused NS_AVAILABLE_IOS(9_0); // NO by default
#endif
@property (readonly, nonatomic, getter=isFocused) BOOL focused NS_AVAILABLE_IOS(9_0);

@property (nonatomic) UISemanticContentAttribute semanticContentAttribute NS_AVAILABLE_IOS(9_0);

// This method returns the layout direction implied by the provided semantic content attribute relative to the application-wide layout direction (as returned by UIApplication.sharedApplication.userInterfaceLayoutDirection).
+ (UIUserInterfaceLayoutDirection)userInterfaceLayoutDirectionForSemanticContentAttribute:(UISemanticContentAttribute)attribute NS_AVAILABLE_IOS(9_0);

// This method returns the layout direction implied by the provided semantic content attribute relative to the provided layout direction. For example, when provided a layout direction of RightToLeft and a semantic content attribute of Playback, this method returns LeftToRight. Layout and drawing code can use this method to determine how to arrange elements, but might find it easier to query the container view’s effectiveUserInterfaceLayoutDirection property instead.
+ (UIUserInterfaceLayoutDirection)userInterfaceLayoutDirectionForSemanticContentAttribute:(UISemanticContentAttribute)semanticContentAttribute relativeToLayoutDirection:(UIUserInterfaceLayoutDirection)layoutDirection NS_AVAILABLE_IOS(10_0);

// Returns the user interface layout direction appropriate for arranging the immediate content of this view. Always consult the effectiveUserInterfaceLayoutDirection of the view whose immediate content is being arranged or drawn. Do not assume that the value propagates through the view’s subtree.
@property (readonly, nonatomic) UIUserInterfaceLayoutDirection effectiveUserInterfaceLayoutDirection NS_AVAILABLE_IOS(10_0);

@end

@interface UIView(UIViewGeometry)

// animatable. do not use frame if view is transformed since it will not correctly reflect the actual location of the view. use bounds + center instead.
@property(nonatomic) CGRect            frame;

// use bounds/center and not frame if non-identity transform. if bounds dimension is odd, center may be have fractional part
@property(nonatomic) CGRect            bounds;      // default bounds is zero origin, frame size. animatable
@property(nonatomic) CGPoint           center;      // center is center of frame. animatable
@property(nonatomic) CGAffineTransform transform;   //二维变形, 仿射变换, 形变属性(平(位)移\缩放\旋转)  // default is CGAffineTransformIdentity. animatable
@property(nonatomic) CGFloat           contentScaleFactor NS_AVAILABLE_IOS(4_0);

@property(nonatomic,getter=isMultipleTouchEnabled) BOOL multipleTouchEnabled __TVOS_PROHIBITED;   // default is NO//YES:支持多点触摸
@property(nonatomic,getter=isExclusiveTouch) BOOL       exclusiveTouch __TVOS_PROHIBITED//(禁止);         // default is NO

- (nullable UIView *)hitTest:(CGPoint)point withEvent:(nullable UIEvent *)event;   // recursively calls -pointInside:withEvent:. point is in the receiver's coordinate system
- (BOOL)pointInside:(CGPoint)point withEvent:(nullable UIEvent *)event;   // default returns YES if point is in bounds

//http://www.jianshu.com/p/92e2d0200eb4
- (CGPoint)convertPoint:(CGPoint)point toView:(nullable UIView *)view;
- (CGPoint)convertPoint:(CGPoint)point fromView:(nullable UIView *)view;
- (CGRect)convertRect:(CGRect)rect toView:(nullable UIView *)view;
- (CGRect)convertRect:(CGRect)rect fromView:(nullable UIView *)view;

@property(nonatomic) BOOL               autoresizesSubviews; // default is YES. if set, subviews are adjusted according to their autoresizingMask if self.bounds changes
@property(nonatomic) UIViewAutoresizing autoresizingMask;    // simple resize. default is UIViewAutoresizingNone

//这个不懂啊
- (CGSize)sizeThatFits:(CGSize)size;     // return 'best' size to fit given size. does not actually resize view. Default is return existing view size
- (void)sizeToFit;                       // calls sizeThatFits: with current view bounds and changes bounds size.

@end

@interface UIView(UIViewHierarchy)

@property(nullable, nonatomic,readonly) UIView       *superview;
@property(nonatomic,readonly,copy) NSArray<__kindof UIView *> *subviews;
@property(nullable, nonatomic,readonly) UIWindow     *window;

- (void)removeFromSuperview;
- (void)insertSubview:(UIView *)view atIndex:(NSInteger)index;
- (void)exchangeSubviewAtIndex:(NSInteger)index1 withSubviewAtIndex:(NSInteger)index2;

- (void)addSubview:(UIView *)view;
- (void)insertSubview:(UIView *)view belowSubview:(UIView *)siblingSubview;
- (void)insertSubview:(UIView *)view aboveSubview:(UIView *)siblingSubview;

- (void)bringSubviewToFront:(UIView *)view;
- (void)sendSubviewToBack:(UIView *)view;

- (void)didAddSubview:(UIView *)subview;
- (void)willRemoveSubview:(UIView *)subview;

- (void)willMoveToSuperview:(nullable UIView *)newSuperview;
- (void)didMoveToSuperview;
- (void)willMoveToWindow:(nullable UIWindow *)newWindow;
- (void)didMoveToWindow;

- (BOOL)isDescendantOfView:(UIView *)view;  // returns YES for self.//是不是view的子控件或者子控件的子控件(是否为view的后代)
- (nullable __kindof UIView *)viewWithTag:(NSInteger)tag; // recursive search. includes self //通过tag获得对应的subview，包括自己

//简单来说，第一步就是设置constrants
//第二步layout
//第三步display

// Allows you to perform layout before the drawing cycle happens. -layoutIfNeeded forces layout early
- (void)setNeedsLayout;//调用 setNeedsLayout 方法以标记该视图（或者它的子视图）为需要进行布局更新
//setNeedsLayout 会给当前 UIView 立一个 flag，以表示后续应该调用 layoutSubviews 方法，以调整当前视图及其子视图的布局
//每一个run loop结束时更新

- (void)layoutIfNeeded;//立即更新
//可以看出 layoutIfNeeded 作为一个辅助选项给了 setNeedsLayout 一个可以瞬时执行的特点。当然默认这个“选项”是关闭的。

- (void)layoutSubviews;    // override point. called by layoutIfNeeded automatically. As of iOS 6.0, when constraints-based layout is used the base implementation applies the constraints-based layout, otherwise it does nothing.
//layoutSubviews调整布局
//在 view controller 的根 view 上调用 layoutSubviews 方法。该方法默认会使用当前可用的约束来计算新的 layout 信息，然后在 subview 上依次调用 layoutSubviews 方法

/* -layoutMargins returns a set of insets from the edge of the view's bounds that denote a default spacing for laying out content.
 If preservesSuperviewLayoutMargins is YES, margins cascade down the view tree, adjusting for geometry offsets, so that setting
 the left value of layoutMargins on a superview will affect the left value of layoutMargins for subviews positioned close to the
 left edge of their superview's bounds
   If your view subclass uses layoutMargins in its layout or drawing, override -layoutMarginsDidChange in order to refresh your 
 view if the margins change.
   On iOS 11.0 and later, please support both user interface layout directions by setting the directionalLayoutMargins property
 instead of the layoutMargins property. After setting the directionalLayoutMargins property, the values in the left and right
 fields of the layoutMargins property will depend on the user interface layout direction.
 */
@property (nonatomic) UIEdgeInsets layoutMargins NS_AVAILABLE_IOS(8_0);

/* directionalLayoutMargins.leading is used on the left when the user interface direction is LTR and on the right for RTL.
 Vice versa for directionalLayoutMargins.trailing.
 */
@property (nonatomic) NSDirectionalEdgeInsets directionalLayoutMargins API_AVAILABLE(ios(11.0),tvos(11.0));

@property (nonatomic) BOOL preservesSuperviewLayoutMargins NS_AVAILABLE_IOS(8_0); // default is NO - set to enable pass-through or cascading behavior of margins from this view’s parent to its children
@property (nonatomic) BOOL insetsLayoutMarginsFromSafeArea API_AVAILABLE(ios(11.0),tvos(11.0));  // Default: YES

- (void)layoutMarginsDidChange NS_AVAILABLE_IOS(8_0);

@property (nonatomic,readonly) UIEdgeInsets safeAreaInsets API_AVAILABLE(ios(11.0),tvos(11.0));
- (void)safeAreaInsetsDidChange API_AVAILABLE(ios(11.0),tvos(11.0));

/* The edges of this guide are constrained to equal the edges of the view inset by the layoutMargins
 */
@property(readonly,strong) UILayoutGuide *layoutMarginsGuide NS_AVAILABLE_IOS(9_0);

/// This content guide provides a layout area that you can use to place text and related content whose width should generally be constrained to a size that is easy for the user to read. This guide provides a centered region that you can place content within to get this behavior for this view.
@property (nonatomic, readonly, strong) UILayoutGuide *readableContentGuide  NS_AVAILABLE_IOS(9_0);

/* The top of the safeAreaLayoutGuide indicates the unobscured top edge of the view (e.g, not behind
 the status bar or navigation bar, if present). Similarly for the other edges.
 */
@property(nonatomic,readonly,strong) UILayoutGuide *safeAreaLayoutGuide API_AVAILABLE(ios(11.0),tvos(11.0));
@end


//http://www.jianshu.com/p/e1eca032be15
//https://stackoverflow.com/questions/2807137/what-is-the-relationship-between-uiviews-setneedslayout-layoutifneeded-and-lay
@interface UIView(UIViewRendering)
//* （注意：rendering与有无自动布局无关，只是单纯的将控件渲染/展示在屏幕上）当 只需要自身定制一款view时，需要重写
- (void)drawRect:(CGRect)rect;//绘制、重绘，子类override

- (void)setNeedsDisplay;//调用 setNeedsDisplay 或者 setNeedsDisplayInRect: 方法以标记该视图（或者它的子视图）需要进行重画//标记为需要重绘，异步调用drawRect
//setNeedsDisplayInRect: 会给当前 UIView 立一个 flag，以表示后续应该调用 drawRect: 方法，以进行视图重绘//
- (void)setNeedsDisplayInRect:(CGRect)rect;//标记为需要局部重绘

@property(nonatomic)                 BOOL              clipsToBounds;              // When YES, content and subviews are clipped to the bounds of the view. Default is NO.
@property(nullable, nonatomic,copy)            UIColor          *backgroundColor UI_APPEARANCE_SELECTOR; // default is nil. Can be useful with the appearance proxy on custom UIView subclasses.
@property(nonatomic)                 CGFloat           alpha;                      // animatable. default is 1.0
@property(nonatomic,getter=isOpaque) BOOL              opaque;                     // default is YES. opaque views must fill their entire bounds or the results are undefined. the active CGContext in drawRect: will not have been cleared and may have non-zeroed pixels
@property(nonatomic)                 BOOL              clearsContextBeforeDrawing; // default is YES. ignored for opaque views. for non-opaque views causes the active CGContext in drawRect: to be pre-filled with transparent pixels
@property(nonatomic,getter=isHidden) BOOL              hidden;                     // default is NO. doesn't check superviews
@property(nonatomic)                 UIViewContentMode contentMode;                // default is UIViewContentModeScaleToFill
@property(nonatomic)                 CGRect            contentStretch NS_DEPRECATED_IOS(3_0,6_0) __TVOS_PROHIBITED; // animatable. default is unit rectangle {{0,0} {1,1}}. Now deprecated: please use -[UIImage resizableImageWithCapInsets:] to achieve the same effect.

@property(nullable, nonatomic,strong)          UIView           *maskView NS_AVAILABLE_IOS(8_0);

/*
 -tintColor always returns a color. The color returned is the first non-default value in the receiver's superview chain (starting with itself).
 If no non-default value is found, a system-defined color is returned.
 If this view's -tintAdjustmentMode returns Dimmed, then the color that is returned for -tintColor will automatically be dimmed.
 If your view subclass uses tintColor in its rendering, override -tintColorDidChange in order to refresh the rendering if the color changes.
 */
@property(null_resettable, nonatomic, strong) UIColor *tintColor NS_AVAILABLE_IOS(7_0);

/*
 -tintAdjustmentMode always returns either UIViewTintAdjustmentModeNormal or UIViewTintAdjustmentModeDimmed. The value returned is the first non-default value in the receiver's superview chain (starting with itself).
 If no non-default value is found, UIViewTintAdjustmentModeNormal is returned.
 When tintAdjustmentMode has a value of UIViewTintAdjustmentModeDimmed for a view, the color it returns from tintColor will be modified to give a dimmed appearance.
 When the tintAdjustmentMode of a view changes (either the view's value changing or by one of its superview's values changing), -tintColorDidChange will be called to allow the view to refresh its rendering.
 */
@property(nonatomic) UIViewTintAdjustmentMode tintAdjustmentMode NS_AVAILABLE_IOS(7_0);

/*
 The -tintColorDidChange message is sent to appropriate subviews of a view when its tintColor is changed by client code or to subviews in the view hierarchy of a view whose tintColor is implicitly changed when its superview or tintAdjustmentMode changes.
 */
- (void)tintColorDidChange NS_AVAILABLE_IOS(7_0);

@end

@interface UIView(UIViewAnimation)

+ (void)beginAnimations:(nullable NSString *)animationID context:(nullable void *)context;  // additional context info passed to will start/did stop selectors. begin/commit can be nested
+ (void)commitAnimations;                                                 // starts up any animations when the top level animation is commited

// no getters. if called outside animation block, these setters have no effect.
+ (void)setAnimationDelegate:(nullable id)delegate;                          // default = nil
+ (void)setAnimationWillStartSelector:(nullable SEL)selector;                // default = NULL. -animationWillStart:(NSString *)animationID context:(void *)context
+ (void)setAnimationDidStopSelector:(nullable SEL)selector;                  // default = NULL. -animationDidStop:(NSString *)animationID finished:(NSNumber *)finished context:(void *)context
+ (void)setAnimationDuration:(NSTimeInterval)duration;              // default = 0.2
+ (void)setAnimationDelay:(NSTimeInterval)delay;                    // default = 0.0
+ (void)setAnimationStartDate:(NSDate *)startDate;                  // default = now ([NSDate date])
+ (void)setAnimationCurve:(UIViewAnimationCurve)curve;              // default = UIViewAnimationCurveEaseInOut
+ (void)setAnimationRepeatCount:(float)repeatCount;                 // default = 0.0.  May be fractional
+ (void)setAnimationRepeatAutoreverses:(BOOL)repeatAutoreverses;    // default = NO. used if repeat count is non-zero
+ (void)setAnimationBeginsFromCurrentState:(BOOL)fromCurrentState;  // default = NO. If YES, the current view position is always used for new animations -- allowing animations to "pile up" on each other. Otherwise, the last end state is used for the animation (the default).

+ (void)setAnimationTransition:(UIViewAnimationTransition)transition forView:(UIView *)view cache:(BOOL)cache;  // current limitation - only one per begin/commit block

+ (void)setAnimationsEnabled:(BOOL)enabled;                         // ignore any attribute changes while set.
#if UIKIT_DEFINE_AS_PROPERTIES
@property(class, nonatomic, readonly) BOOL areAnimationsEnabled;
#else
+ (BOOL)areAnimationsEnabled;
#endif
+ (void)performWithoutAnimation:(void (NS_NOESCAPE ^)(void))actionsWithoutAnimation NS_AVAILABLE_IOS(7_0);

#if UIKIT_DEFINE_AS_PROPERTIES
@property(class, nonatomic, readonly) NSTimeInterval inheritedAnimationDuration NS_AVAILABLE_IOS(9_0);
#else
+ (NSTimeInterval)inheritedAnimationDuration NS_AVAILABLE_IOS(9_0);
#endif

@end

@interface UIView(UIViewAnimationWithBlocks) //动画+block

+ (void)animateWithDuration:(NSTimeInterval)duration delay:(NSTimeInterval)delay options:(UIViewAnimationOptions)options animations:(void (^)(void))animations completion:(void (^ __nullable)(BOOL finished))completion NS_AVAILABLE_IOS(4_0);

+ (void)animateWithDuration:(NSTimeInterval)duration animations:(void (^)(void))animations completion:(void (^ __nullable)(BOOL finished))completion NS_AVAILABLE_IOS(4_0); // delay = 0.0, options = 0

+ (void)animateWithDuration:(NSTimeInterval)duration animations:(void (^)(void))animations NS_AVAILABLE_IOS(4_0); // delay = 0.0, options = 0, completion = NULL

/* Performs `animations` using a timing curve described by the motion of a spring. When `dampingRatio` is 1, the animation will smoothly decelerate to its final model values without oscillating. Damping ratios less than 1 will oscillate more and more before coming to a complete stop. You can use the initial spring velocity to specify how fast the object at the end of the simulated spring was moving before it was attached. It's a unit coordinate system, where 1 is defined as travelling the total animation distance in a second. So if you're changing an object's position by 200pt in this animation, and you want the animation to behave as if the object was moving at 100pt/s before the animation started, you'd pass 0.5. You'll typically want to pass 0 for the velocity. */ 
+ (void)animateWithDuration:(NSTimeInterval)duration delay:(NSTimeInterval)delay usingSpringWithDamping:(CGFloat)dampingRatio initialSpringVelocity:(CGFloat)velocity options:(UIViewAnimationOptions)options animations:(void (^)(void))animations completion:(void (^ __nullable)(BOOL finished))completion NS_AVAILABLE_IOS(7_0);

+ (void)transitionWithView:(UIView *)view duration:(NSTimeInterval)duration options:(UIViewAnimationOptions)options animations:(void (^ __nullable)(void))animations completion:(void (^ __nullable)(BOOL finished))completion NS_AVAILABLE_IOS(4_0);

+ (void)transitionFromView:(UIView *)fromView toView:(UIView *)toView duration:(NSTimeInterval)duration options:(UIViewAnimationOptions)options completion:(void (^ __nullable)(BOOL finished))completion NS_AVAILABLE_IOS(4_0); // toView added to fromView.superview, fromView removed from its superview

/* Performs the requested system-provided animation on one or more views. Specify addtional animations in the parallelAnimations block. These additional animations will run alongside the system animation with the same timing and duration that the system animation defines/inherits. Additional animations should not modify properties of the view on which the system animation is being performed. Not all system animations honor all available options.
 */
+ (void)performSystemAnimation:(UISystemAnimation)animation onViews:(NSArray<__kindof UIView *> *)views options:(UIViewAnimationOptions)options animations:(void (^ __nullable)(void))parallelAnimations completion:(void (^ __nullable)(BOOL finished))completion NS_AVAILABLE_IOS(7_0);

@end

@interface UIView (UIViewKeyframeAnimations)

+ (void)animateKeyframesWithDuration:(NSTimeInterval)duration delay:(NSTimeInterval)delay options:(UIViewKeyframeAnimationOptions)options animations:(void (^)(void))animations completion:(void (^ __nullable)(BOOL finished))completion NS_AVAILABLE_IOS(7_0);
+ (void)addKeyframeWithRelativeStartTime:(double)frameStartTime relativeDuration:(double)frameDuration animations:(void (^)(void))animations NS_AVAILABLE_IOS(7_0); // start time and duration are values between 0.0 and 1.0 specifying time and duration relative to the overall time of the keyframe animation

@end

@interface UIView (UIViewGestureRecognizers)

@property(nullable, nonatomic,copy) NSArray<__kindof UIGestureRecognizer *> *gestureRecognizers NS_AVAILABLE_IOS(3_2);

- (void)addGestureRecognizer:(UIGestureRecognizer*)gestureRecognizer NS_AVAILABLE_IOS(3_2);
- (void)removeGestureRecognizer:(UIGestureRecognizer*)gestureRecognizer NS_AVAILABLE_IOS(3_2);

// called when the recognizer attempts to transition out of UIGestureRecognizerStatePossible if a touch hit-tested to this view will be cancelled as a result of gesture recognition
// returns YES by default. return NO to cause the gesture recognizer to transition to UIGestureRecognizerStateFailed
// subclasses may override to prevent recognition of particular gestures. for example, UISlider prevents swipes parallel to the slider that start in the thumb
- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gestureRecognizer NS_AVAILABLE_IOS(6_0);

@end
    
@interface UIView (UIViewMotionEffects)

/*! Begins applying `effect` to the receiver. The effect's emitted keyPath/value pairs will be
    applied to the view's presentation layer.
 
    Animates the transition to the motion effect's values using the present UIView animation
    context. */
- (void)addMotionEffect:(UIMotionEffect *)effect NS_AVAILABLE_IOS(7_0);

/*! Stops applying `effect` to the receiver. Any affected presentation values will animate to
    their post-removal values using the present UIView animation context. */
- (void)removeMotionEffect:(UIMotionEffect *)effect NS_AVAILABLE_IOS(7_0);

@property (copy, nonatomic) NSArray<__kindof UIMotionEffect *> *motionEffects NS_AVAILABLE_IOS(7_0);

@end


//
// UIView Constraint-based Layout Support
//

typedef NS_ENUM(NSInteger, UILayoutConstraintAxis) {
    UILayoutConstraintAxisHorizontal = 0,
    UILayoutConstraintAxisVertical = 1
};

// Installing Constraints

/* A constraint is typically installed on the closest common ancestor of the views involved in the constraint. 
 It is required that a constraint be installed on _a_ common ancestor of every view involved.  The numbers in a constraint are interpreted in the coordinate system of the view it is installed on.  A view is considered to be an ancestor of itself.
 */
@interface UIView (UIConstraintBasedLayoutInstallingConstraints)//约束的添加和删除

@property(nonatomic,readonly) NSArray<__kindof NSLayoutConstraint *> *constraints NS_AVAILABLE_IOS(6_0);

- (void)addConstraint:(NSLayoutConstraint *)constraint NS_AVAILABLE_IOS(6_0); // This method will be deprecated in a future release and should be avoided.  Instead, set NSLayoutConstraint's active property to YES.
- (void)addConstraints:(NSArray<__kindof NSLayoutConstraint *> *)constraints NS_AVAILABLE_IOS(6_0); // This method will be deprecated in a future release and should be avoided.  Instead use +[NSLayoutConstraint activateConstraints:].
- (void)removeConstraint:(NSLayoutConstraint *)constraint NS_AVAILABLE_IOS(6_0); // This method will be deprecated in a future release and should be avoided.  Instead set NSLayoutConstraint's active property to NO.
- (void)removeConstraints:(NSArray<__kindof NSLayoutConstraint *> *)constraints NS_AVAILABLE_IOS(6_0); // This method will be deprecated in a future release and should be avoided.  Instead use +[NSLayoutConstraint deactivateConstraints:].
@end



//http://chesterlee.github.io/blog/2014/10/13/the-interface-of-the-autolayout/
// Core Layout Methods

/* To render a window, the following passes will occur, if necessary.  
 
 update constraints
 layout
 display
 //在这里解释得清清楚楚，看什么博客啊
 
 
 Please see the conceptual documentation for a discussion of these methods.
 */
//http://www.jianshu.com/p/b8b0a50dc5f2
@interface UIView (UIConstraintBasedLayoutCoreMethods) //约束的核心函数
- (void)updateConstraintsIfNeeded NS_AVAILABLE_IOS(6_0); // Updates the constraints from the bottom up for the view hierarchy rooted at the receiver. UIWindow's implementation creates a layout engine if necessary first.
//从subview到superview顺序执行，系统UIWindow's在需要时，立即触发约束更新，自动更新布局
//

//当用自动布局时，系统自动调用。需要手动重写： - (void)updateContraints {}把添加约束的方法、代码写在这里面。注意调用[super updateContraints]；
- (void)updateConstraints NS_AVAILABLE_IOS(6_0) NS_REQUIRES_SUPER; // Override this to adjust your special constraints during a constraints update pass

- (BOOL)needsUpdateConstraints NS_AVAILABLE_IOS(6_0);//constraint-based layout system使用此返回值去决定是否需要调用updateConstraints作为正常布局过程的一部分

- (void)setNeedsUpdateConstraints NS_AVAILABLE_IOS(6_0);//当一个自定义view的某个属性发生改变，并且可能影响到constraint时，需要调用此方法去标记constraints需要在未来的某个点更新，系统然后调用updateConstraints.

@end

// Compatibility and Adoption

@interface UIView (UIConstraintBasedCompatibility) //约束特性的打开和关闭,也就是兼容性

/* By default, the autoresizing mask on a view gives rise to constraints that fully determine 
 the view's position.默认情况下，autoresizing mask产生约束，然后去决定view的位置
 
 This allows the auto layout system to track the frames of views whose
 layout is controlled manually (through -setFrame:, for example).
 这允许al ...
 When you elect to position the view using auto layout by adding your own constraints, 
 you must set this property to NO. IB will do this for you.(这句话相当重要)
 
//如果手动添加约束，就需要call这个接口，默认的view是添加了autoresizing mask的，
此时需要把他关闭，把此方法的flag传递为NO即可。但是SB/Xib会自动帮你做这个事情。
仅仅手动添加约束需要。
- (void)setTranslatesAutoresizingMaskIntoConstraints:(BOOL)flag NS_AVAILABLE_IOS(6_0);
*/

@property(nonatomic) BOOL translatesAutoresizingMaskIntoConstraints NS_AVAILABLE_IOS(6_0); // Default YES http://www.jianshu.com/p/aca357d2bfd8  查询当前是否使用的Autoresizing，也可以设置为NO，去关闭这个

/*
 //约束的Layout方式是lazily使用的。如果你在-updateConstraints中来初始化你的约束，
 但是如果没有添加约束的话，系统就不会调用这个-updateConstraints接口。
 这个就是鸡和蛋的问题，所以用这个方法在自定义的view中返回YES，表示一定要用AL来约束。
 比如在一个Cell内部，如果在-updateConstraints进行了constraint的更新，添加删除等，
 那么就调用此接口。
 + (BOOL)requiresConstraintBasedLayout NS_AVAILABLE_IOS(6_0);
 */
/* constraint-based layout engages lazily when someone tries to use it (e.g., adds a constraint to a view).  If you do all of your constraint set up in -updateConstraints, you might never even receive updateConstraints if no one makes a constraint.  To fix this chicken and egg problem, override this method to return YES if your view needs the window to use constraint-based layout.  
 */
#if UIKIT_DEFINE_AS_PROPERTIES
@property(class, nonatomic, readonly) BOOL requiresConstraintBasedLayout NS_AVAILABLE_IOS(6_0);//仅仅是一个查询的作用
#else
+ (BOOL)requiresConstraintBasedLayout NS_AVAILABLE_IOS(6_0);//所以用这个方法在自定义的view中返回YES，表示一定要用AL来约束。
#endif

@end

// Separation of Concerns

@interface UIView (UIConstraintBasedLayoutLayering)

/* Constraints do not actually relate the frames of the views, rather they relate the "alignment rects" of views.  This is the same as the frame unless overridden by a subclass of UIView.  Alignment rects are the same as the "layout rects" shown in Interface Builder 3.  Typically the alignment rect of a view is what the end user would think of as the bounding rect around a control, omitting ornamentation like shadows and engraving lines.  The edges of the alignment rect are what is interesting to align, not the shadows and such.  
 */

/* These two methods should be inverses of each other.  UIKit will call both as part of layout computation.
 They may be overridden to provide arbitrary transforms between frame and alignment rect, though the two methods must be inverses of each other.
 However, the default implementation uses -alignmentRectInsets, so just override that if it's applicable.  It's easier to get right. 
 A view that displayed an image with some ornament would typically override these, because the ornamental part of an image would scale up with the size of the frame.  
 Set the NSUserDefault UIViewShowAlignmentRects to YES to see alignment rects drawn.
 */

- (CGRect)alignmentRectForFrame:(CGRect)frame NS_AVAILABLE_IOS(6_0);//设置view在当前Frame下对应的alignmentRect的值，这个是AL系统回调函数
- (CGRect)frameForAlignmentRect:(CGRect)alignmentRect NS_AVAILABLE_IOS(6_0);//设置view在当前alignmentRect下对应的frame的值，这个是AL系统回调函数

/* override this if the alignment rect is obtained from the frame by insetting each edge by a fixed amount.  This is only called by alignmentRectForFrame: and frameForAlignmentRect:.
 */
#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly) UIEdgeInsets alignmentRectInsets NS_AVAILABLE_IOS(6_0);
#else
- (UIEdgeInsets)alignmentRectInsets NS_AVAILABLE_IOS(6_0);//设置当前view计算alignment rect所需要用到UIEdgeInsets值，比较常用
#endif
//什么是baseline
- (UIView *)viewForBaselineLayout NS_DEPRECATED_IOS(6_0, 9_0, "Override -viewForFirstBaselineLayout or -viewForLastBaselineLayout as appropriate, instead") __TVOS_PROHIBITED;

/* -viewForFirstBaselineLayout is called by the constraints system when interpreting
 the firstBaseline attribute for a view.
    For complex custom UIView subclasses, override this method to return the text-based
 (i.e., UILabel or non-scrollable UITextView) descendant of the receiver whose first baseline
 is appropriate for alignment.
    UIView's implementation returns [self viewForLastBaselineLayout], so if the same 
 descendant is appropriate for both first- and last-baseline layout you may override
 just -viewForLastBaselineLayout.
 */
@property(readonly,strong) UIView *viewForFirstBaselineLayout NS_AVAILABLE_IOS(9_0);

/* -viewForLastBaselineLayout is called by the constraints system when interpreting
 the lastBaseline attribute for a view.
    For complex custom UIView subclasses, override this method to return the text-based
 (i.e., UILabel or non-scrollable UITextView) descendant of the receiver whose last baseline
 is appropriate for alignment.
    UIView's implementation returns self.
 */
@property(readonly,strong) UIView *viewForLastBaselineLayout NS_AVAILABLE_IOS(9_0);

/* Override this method to tell the layout system that there is something it doesn't natively understand in this view, and this is how large it intrinsically is.  A typical example would be a single line text field.  The layout system does not understand text - it must just be told that there's something in the view, and that that something will take a certain amount of space if not clipped.  
 
 In response, UIKit will set up constraints that specify (1) that the opaque content should not be compressed or clipped, (2) that the view prefers to hug tightly to its content. 
 
 A user of a view may need to specify the priority of these constraints.  For example, by default, a push button 
 -strongly wants to hug its content in the vertical direction (buttons really ought to be their natural height)
 -weakly hugs its content horizontally (extra side padding between the title and the edge of the bezel is acceptable)
 -strongly resists compressing or clipping content in both directions. 
 
 However, you might have a case where you'd prefer to show all the available buttons with truncated text rather than losing some of the buttons. The truncation might only happen in portrait orientation but not in landscape, for example. In that case you'd want to setContentCompressionResistancePriority:forAxis: to (say) UILayoutPriorityDefaultLow for the horizontal axis.
 
 The default 'strong' and 'weak' priorities referred to above are UILayoutPriorityDefaultHigh and UILayoutPriorityDefaultLow.  
 
 Note that not all views have an intrinsicContentSize.  UIView's default implementation is to return (UIViewNoIntrinsicMetric, UIViewNoIntrinsicMetric).  The _intrinsic_ content size is concerned only with data that is in the view itself, not in other views. Remember that you can also set constant width or height constraints on any view, and you don't need to override instrinsicContentSize if these dimensions won't be changing with changing view content.
 */
UIKIT_EXTERN const CGFloat UIViewNoIntrinsicMetric NS_AVAILABLE_IOS(6_0); // -1
#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly) CGSize intrinsicContentSize NS_AVAILABLE_IOS(6_0);
#else
- (CGSize)intrinsicContentSize NS_AVAILABLE_IOS(6_0);
#endif
- (void)invalidateIntrinsicContentSize NS_AVAILABLE_IOS(6_0); // call this when something changes that affects the intrinsicContentSize.  Otherwise UIKit won't notice that it changed.  

- (UILayoutPriority)contentHuggingPriorityForAxis:(UILayoutConstraintAxis)axis NS_AVAILABLE_IOS(6_0);
- (void)setContentHuggingPriority:(UILayoutPriority)priority forAxis:(UILayoutConstraintAxis)axis NS_AVAILABLE_IOS(6_0);

- (UILayoutPriority)contentCompressionResistancePriorityForAxis:(UILayoutConstraintAxis)axis NS_AVAILABLE_IOS(6_0);
- (void)setContentCompressionResistancePriority:(UILayoutPriority)priority forAxis:(UILayoutConstraintAxis)axis NS_AVAILABLE_IOS(6_0);
@end

// Size To Fit

UIKIT_EXTERN const CGSize UILayoutFittingCompressedSize NS_AVAILABLE_IOS(6_0);//一个标记，按可以展示内容最小的压缩大小来Layout对应的size（常用）
UIKIT_EXTERN const CGSize UILayoutFittingExpandedSize NS_AVAILABLE_IOS(6_0);//一个标记，按可以展示内容可扩张最大的大小来Layout对应的size，没查到是以怎样的标准来计算的

@interface UIView (UIConstraintBasedLayoutFittingSize) //AutoLayout的Size计算

//配合UILayoutFittingCompressSize和UILayoutFittingExpandedSize来使用，
//在当前view的subviews的intrinsic size都可以计算的情况下，可以获取最小压缩（UILayoutFittingCompressSize）
//的size或最大（UILayoutFittingExpandedSize）的size。

/* The size fitting most closely to targetSize in which the receiver's subtree can be laid out while optimally satisfying the constraints.
 
 If you want the smallest possible size, pass UILayoutFittingCompressedSize; for the largest possible size, pass UILayoutFittingExpandedSize.
 Also see the comment for UILayoutPriorityFittingSizeLevel.
 */
- (CGSize)systemLayoutSizeFittingSize:(CGSize)targetSize NS_AVAILABLE_IOS(6_0); // Equivalent to sending -systemLayoutSizeFittingSize:withHorizontalFittingPriority:verticalFittingPriority: with UILayoutPriorityFittingSizeLevel for both priorities.

- (CGSize)systemLayoutSizeFittingSize:(CGSize)targetSize withHorizontalFittingPriority:(UILayoutPriority)horizontalFittingPriority verticalFittingPriority:(UILayoutPriority)verticalFittingPriority NS_AVAILABLE_IOS(8_0);//在两个方向上做不同类型的Fit size计算，相对而言，systemLayoutSizeFittingSize是在两个方向上都一致（都是Compressed或都是Expanded）的用法。
@end

@interface UIView (UILayoutGuideSupport)

/* UILayoutGuide objects owned by the receiver.
 */
@property(nonatomic,readonly,copy) NSArray<__kindof UILayoutGuide *> *layoutGuides NS_AVAILABLE_IOS(9_0);

/* Adds layoutGuide to the receiver, passing the receiver in -setOwningView: to layoutGuide.
 */
- (void)addLayoutGuide:(UILayoutGuide *)layoutGuide NS_AVAILABLE_IOS(9_0);

/* Removes layoutGuide from the receiver, passing nil in -setOwningView: to layoutGuide.
 */
- (void)removeLayoutGuide:(UILayoutGuide *)layoutGuide NS_AVAILABLE_IOS(9_0);
@end

@class NSLayoutXAxisAnchor,NSLayoutYAxisAnchor,NSLayoutDimension;
@interface UIView (UIViewLayoutConstraintCreation)
/* Constraint creation conveniences. See NSLayoutAnchor.h for details.
 */
@property(nonatomic,readonly,strong) NSLayoutXAxisAnchor *leadingAnchor NS_AVAILABLE_IOS(9_0);
@property(nonatomic,readonly,strong) NSLayoutXAxisAnchor *trailingAnchor NS_AVAILABLE_IOS(9_0);
@property(nonatomic,readonly,strong) NSLayoutXAxisAnchor *leftAnchor NS_AVAILABLE_IOS(9_0);
@property(nonatomic,readonly,strong) NSLayoutXAxisAnchor *rightAnchor NS_AVAILABLE_IOS(9_0);
@property(nonatomic,readonly,strong) NSLayoutYAxisAnchor *topAnchor NS_AVAILABLE_IOS(9_0);
@property(nonatomic,readonly,strong) NSLayoutYAxisAnchor *bottomAnchor NS_AVAILABLE_IOS(9_0);
@property(nonatomic,readonly,strong) NSLayoutDimension *widthAnchor NS_AVAILABLE_IOS(9_0);
@property(nonatomic,readonly,strong) NSLayoutDimension *heightAnchor NS_AVAILABLE_IOS(9_0);
@property(nonatomic,readonly,strong) NSLayoutXAxisAnchor *centerXAnchor NS_AVAILABLE_IOS(9_0);
@property(nonatomic,readonly,strong) NSLayoutYAxisAnchor *centerYAnchor NS_AVAILABLE_IOS(9_0);
@property(nonatomic,readonly,strong) NSLayoutYAxisAnchor *firstBaselineAnchor NS_AVAILABLE_IOS(9_0);
@property(nonatomic,readonly,strong) NSLayoutYAxisAnchor *lastBaselineAnchor NS_AVAILABLE_IOS(9_0);

@end

// Debugging

/* Everything in this section should be used in debugging only, never in shipping code.  These methods may not exist in the future - no promises.  
 */
@interface UIView (UIConstraintBasedLayoutDebugging)

/* This returns a list of all the constraints that are affecting the current location of the receiver.  The constraints do not necessarily involve the receiver, they may affect the frame indirectly.
 Pass UILayoutConstraintAxisHorizontal for the constraints affecting [self center].x and CGRectGetWidth([self bounds]), and UILayoutConstraintAxisVertical for the constraints affecting[self center].y and CGRectGetHeight([self bounds]).
 */
- (NSArray<__kindof NSLayoutConstraint *> *)constraintsAffectingLayoutForAxis:(UILayoutConstraintAxis)axis NS_AVAILABLE_IOS(6_0);////影响当前方向的约束集合

/* If there aren't enough constraints in the system to uniquely determine layout, we say the layout is ambiguous.  For example, if the only constraint in the system was x = y + 100, then there are lots of different possible values for x and y.  This situation is not automatically detected by UIKit, due to performance considerations and details of the algorithm used for layout.  
 The symptom of ambiguity is that views sometimes jump from place to place, or possibly are just in the wrong place.
 -hasAmbiguousLayout runs a check for whether there is another center and bounds the receiver could have that could also satisfy the constraints.
 -exerciseAmbiguousLayout does more.  It randomly changes the view layout to a different valid layout.  Making the UI jump back and forth can be helpful for figuring out where you're missing a constraint.  
 */
#if UIKIT_DEFINE_AS_PROPERTIES//是否含有含糊不清的约束
@property(nonatomic, readonly) BOOL hasAmbiguousLayout NS_AVAILABLE_IOS(6_0);
#else
- (BOOL)hasAmbiguousLayout NS_AVAILABLE_IOS(6_0);
#endif

- (void)exerciseAmbiguityInLayout NS_AVAILABLE_IOS(6_0); 
@end

/* Everything in this section should be used in debugging only, never in shipping code.  These methods may not exist in the future - no promises.
 */
@interface UILayoutGuide (UIConstraintBasedLayoutDebugging)

/* This returns a list of all the constraints that are affecting the current location of the receiver.  The constraints do not necessarily involve the receiver, they may affect the frame indirectly.
 Pass UILayoutConstraintAxisHorizontal for the constraints affecting [self center].x and CGRectGetWidth([self bounds]), and UILayoutConstraintAxisVertical for the constraints affecting[self center].y and CGRectGetHeight([self bounds]).
 */
- (NSArray<__kindof NSLayoutConstraint *> *)constraintsAffectingLayoutForAxis:(UILayoutConstraintAxis)axis NS_AVAILABLE_IOS(10_0);

/* If there aren't enough constraints in the system to uniquely determine layout, we say the layout is ambiguous.  For example, if the only constraint in the system was x = y + 100, then there are lots of different possible values for x and y.  This situation is not automatically detected by UIKit, due to performance considerations and details of the algorithm used for layout.
 The symptom of ambiguity is that views sometimes jump from place to place, or possibly are just in the wrong place.
 -hasAmbiguousLayout runs a check for whether there is another center and bounds the receiver could have that could also satisfy the constraints.
 */
#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly) BOOL hasAmbiguousLayout NS_AVAILABLE_IOS(10_0);
#else
- (BOOL)hasAmbiguousLayout NS_AVAILABLE_IOS(10_0);
#endif
@end

@interface UIView (UIStateRestoration)
@property (nullable, nonatomic, copy) NSString *restorationIdentifier NS_AVAILABLE_IOS(6_0);
- (void) encodeRestorableStateWithCoder:(NSCoder *)coder NS_AVAILABLE_IOS(6_0);
- (void) decodeRestorableStateWithCoder:(NSCoder *)coder NS_AVAILABLE_IOS(6_0);
@end

@interface UIView (UISnapshotting)
/* 
* When requesting a snapshot, 'afterUpdates' defines whether the snapshot is representative of what's currently on screen or if you wish to include any recent changes before taking the snapshot. 
 
 If called during layout from a committing transaction, snapshots occurring after the screen updates will include all changes made, regardless of when the snapshot is taken and the changes are made. For example:
 
     - (void)layoutSubviews {
         UIView *snapshot = [self snapshotViewAfterScreenUpdates:YES];
         self.alpha = 0.0;
     }
 
 The snapshot will appear to be empty since the change in alpha will be captured by the snapshot. If you need to animate the view during layout, animate the snapshot instead.

* Creating snapshots from existing snapshots (as a method to duplicate, crop or create a resizable variant) is supported. In cases where many snapshots are needed, creating a snapshot from a common superview and making subsequent snapshots from it can be more performant. Please keep in mind that if 'afterUpdates' is YES, the original snapshot is committed and any changes made to it, not the view originally snapshotted, will be included.
 */
- (nullable UIView *)snapshotViewAfterScreenUpdates:(BOOL)afterUpdates NS_AVAILABLE_IOS(7_0);
- (nullable UIView *)resizableSnapshotViewFromRect:(CGRect)rect afterScreenUpdates:(BOOL)afterUpdates withCapInsets:(UIEdgeInsets)capInsets NS_AVAILABLE_IOS(7_0);  // Resizable snapshots will default to stretching the center
// Use this method to render a snapshot of the view hierarchy into the current context. Returns NO if the snapshot is missing image data, YES if the snapshot is complete. Calling this method from layoutSubviews while the current transaction is committing will capture what is currently displayed regardless if afterUpdates is YES.
- (BOOL)drawViewHierarchyInRect:(CGRect)rect afterScreenUpdates:(BOOL)afterUpdates NS_AVAILABLE_IOS(7_0);
@end

NS_ASSUME_NONNULL_END
