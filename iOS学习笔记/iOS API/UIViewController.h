//
//  UIViewController.h
//  UIKit
//
//  Copyright (c) 2007-2017 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Foundation/NSExtensionRequestHandling.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIApplication.h>
#import <UIKit/UIStateRestoration.h>
#import <UIKit/UITraitCollection.h>
#import <UIKit/UIFocus.h>

/*
  UIViewController is a generic controller base class that manages a view.  It has methods that are called
  when a view appears or disappears.
 
  Subclasses can override -loadView to create their custom view hierarchy, or specify a nib name to be loaded
  automatically.  This class is also a good place for delegate & datasource methods, and other controller
  stuff.
*/

NS_ASSUME_NONNULL_BEGIN

@class UIView;
@class UINavigationItem, UIBarButtonItem, UITabBarItem;
@class UISearchDisplayController;
@class UIPopoverController;
@class UIStoryboard, UIStoryboardSegue, UIStoryboardUnwindSegueSource;
@class UIScrollView;
@protocol UIViewControllerTransitionCoordinator;

typedef NS_ENUM(NSInteger, UIModalTransitionStyle) {
    UIModalTransitionStyleCoverVertical = 0,
    UIModalTransitionStyleFlipHorizontal __TVOS_PROHIBITED,
    UIModalTransitionStyleCrossDissolve,
    UIModalTransitionStylePartialCurl NS_ENUM_AVAILABLE_IOS(3_2) __TVOS_PROHIBITED,
};

typedef NS_ENUM(NSInteger, UIModalPresentationStyle) {
        UIModalPresentationFullScreen = 0,
        UIModalPresentationPageSheet NS_ENUM_AVAILABLE_IOS(3_2) __TVOS_PROHIBITED,
        UIModalPresentationFormSheet NS_ENUM_AVAILABLE_IOS(3_2) __TVOS_PROHIBITED,
        UIModalPresentationCurrentContext NS_ENUM_AVAILABLE_IOS(3_2),
        UIModalPresentationCustom NS_ENUM_AVAILABLE_IOS(7_0),
        UIModalPresentationOverFullScreen NS_ENUM_AVAILABLE_IOS(8_0),
        UIModalPresentationOverCurrentContext NS_ENUM_AVAILABLE_IOS(8_0),
        UIModalPresentationPopover NS_ENUM_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED,
        UIModalPresentationBlurOverFullScreen __TVOS_AVAILABLE(11_0) __IOS_PROHIBITED __WATCHOS_PROHIBITED,
        UIModalPresentationNone NS_ENUM_AVAILABLE_IOS(7_0) = -1,
};

@protocol UIContentContainer <NSObject>

@property (nonatomic, readonly) CGSize preferredContentSize NS_AVAILABLE_IOS(8_0);
- (void)preferredContentSizeDidChangeForChildContentContainer:(id <UIContentContainer>)container NS_AVAILABLE_IOS(8_0);

/*
 Intended as a bridge for a view controller that does not use auto layout presenting a child that does use auto layout.
 
 If the child's view is using auto layout and the -systemLayoutSizeFittingSize: of the view
 changes, -systemLayoutFittingSizeDidChangeForChildContentContainer: will be sent to the view controller's parent.
 */
- (void)systemLayoutFittingSizeDidChangeForChildContentContainer:(id <UIContentContainer>)container NS_AVAILABLE_IOS(8_0);

/*
 When the content container forwards viewWillTransitionToSize:withTransitionCoordinator: to its children, it will call this method to determine what size to send them. 
 
 If the returned size is the same as the child container's current size, viewWillTransitionToSize:withTransitionCoordinator: will not be called.
 */
- (CGSize)sizeForChildContentContainer:(id <UIContentContainer>)container withParentContainerSize:(CGSize)parentSize NS_AVAILABLE_IOS(8_0);

/* 
 This method is called when the view controller's view's size is changed by its parent (i.e. for the root view controller when its window rotates or is resized). 
 
 If you override this method, you should either call super to propagate the change to children or manually forward the change to children.
 */
- (void)viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id <UIViewControllerTransitionCoordinator>)coordinator NS_AVAILABLE_IOS(8_0);

/* 
 This method is called when the view controller's trait collection is changed by its parent.
 
 If you override this method, you should either call super to propagate the change to children or manually forward the change to children.
 */
- (void)willTransitionToTraitCollection:(UITraitCollection *)newCollection withTransitionCoordinator:(id <UIViewControllerTransitionCoordinator>)coordinator NS_AVAILABLE_IOS(8_0);

@end

// Sometimes view controllers that are using showViewController:sender and showDetailViewController:sender: will need to know when the split view controller environment above it has changed. This notification will be posted when that happens (for example, when a split view controller is collapsing or expanding). The NSNotification's object will be the view controller that caused the change.
UIKIT_EXTERN NSNotificationName const UIViewControllerShowDetailTargetDidChangeNotification NS_AVAILABLE_IOS(8_0);

NS_CLASS_AVAILABLE_IOS(2_0) @interface UIViewController : UIResponder <NSCoding, UIAppearanceContainer, UITraitEnvironment, UIContentContainer, UIFocusEnvironment>

#pragma mark 初始化
/*
  The designated initializer(指定初始化函数). If you subclass UIViewController, you must call the super implementation of this（调用super）
  method, even if you aren't using a NIB.  (As a convenience, the default init method will do this for you,
  and specify nil for both of this methods arguments.) In the specified NIB, the File's Owner proxy should
  have its class set to your view controller subclass, with the view outlet connected to the main view. If you
  invoke this method with a nil nib name, then this class' -loadView method will attempt to load a NIB whose
  name is the same as your view controller's class. If no such NIB in fact exists then you must either call
  -setView: before -view is invoked, or override the -loadView method to set up your views programatically.
*/
/*1.
 从 Storyboard 中加载
 initWithNibName:bundle: 方法是不会被调用的，不需要我们关注它。加载过程中，会去访问 View Controller 的 view 属性，这时会自动调用 loadView，在这种情况下我们不应该重载 loadView，所以也不需要我们关注它。
 
 这个 View Controller 的 awakeFromNib 方法，以及它的各个 SubViews 的 awakeFromNib 方法都会被调用。接着，需要关注的是 View Controller 及其 Subviews 的 awakeFromNib 方法。
*/
/*nib文件
 2.View Controller 指定的初始化方法是 initWithNibName:bundle:。 如果指定了该方法的 nib，那么会自动从对应的 nib 文件去加载 View Controller。比如：  YourViewController *vc = [YourViewController initWithNibName:@"YourViewController" bundle:nil];
 加载过程中，会去访问 View Controller 的 view 属性，这时会自动调用 loadView，在这种情况下我们不应该重载 loadView，所以也不需要我们关注它。
 
 这个 View Controller 的 awakeFromNib 方法不会被调用，这个不需要我们关注，但是它的各个 SubViews 的 awakeFromNib 方法都会被调用。所以接着，需要关注的是 View Controller 的 Subviews 的 awakeFromNib 方法。
 */
/*3.
 代码方式，可以重写，传入两个nil
 如果你使用指定的初始化方法 initWithNibName:bundle: 并且传递两个参数为 nil，或者你自己定义 View Controller 的 init 类似的方法，这时需要在初始化方法中自己实现相关的代码，当然在这个方法中，你需要调用你的父类的 init 类似的方法。一般不要实现过于复杂的初始化方法，你只用提供出 View Controller 的相关属性让客户在后面调用时再配置它的行为即可。在这种情况下创建的 View Controller ，是不会自动调用 awakeFromNib 方法的，所以不需要我们关注它。但是，在这种情况下，我们通常需要去重载 loadView 方法，所以接着需要关注的是 loadView 方法。
 */
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_DESIGNATED_INITIALIZER;//通过代码创建vc和通过nib文件创建vc时，回调用这个方法；用sb方式创建vc是不会调用的

//从 Storyboard 中加载
//如果是从 Storyboard 中加载 View Controller，当 View Controller 被初始化的时候，archive （在 Storyboard 中用 Interface Builder 中创建的 View Controller 的各种属性会被序列化为归档文件（archive））会被加载到内存进行处理，这个过程是通过自动调用 View Controller 的 initWithCoder: 方法来实现的。
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER; //初始化方法，sb方式初始化vc时，自动调用这个方法;用nib方式也会自动调用，只要对象是从文件解析来的，就会调用

//http://blog.sunnyxx.com/2015/06/12/objc-new-features-in-2015/
//null_resettable设置方法可以为空
@property(null_resettable, nonatomic,strong) UIView *view; // The getter first invokes [self loadView] if the view hasn't been set yet. Subclasses must call super if they override the setter or getter.

//http://www.samirchen.com/view-controller-lifecycle-in-ios/
- (void)loadView; // This is where subclasses should create their custom view hierarchy if they aren't using a nib. Should never be called directly.
//简单讲，第一步，就是loadView
//永远不要直接调用loadView
//当代码访问 View Controller 的 view 时，如果 view 存在，是非 nil 的，那么会直接返回这个 view；如果 view 不存在于内存中，是 nil 的，那么 View Controller 会调用它的 loadView 方法来加载 view hierarchy 到内存并把对象赋值给 view。
//通过上面的内容，我们可以知道如果是从 Storyboard 或 Nib 文件中加载 View Controller，我们都不要去重载 loadView，它会自动加载 view 属性以及它的各个 Subviews。只有当我们自己代码创建 View Controller 的时候，我们可能需要去重载 loadView。当然，如果我们不重载，那么默认情况下 loadView 会创建一个光秃秃的 UIView 对象赋给 view 属性。
1.
/*If you use Interface Builder to create your views and initialize the view controller, you must not override this method.,
 通过interface builder来创建，不要重载这个方法，因为在调用这个方法的时候，xib定制的view还没有定制完。使用xib了，说明应该使用initWithNibName:bundle:方法。
 */
/*You should never call this method directly. The view controller calls this method when its
 view
 property is requested but is currently nil. This method loads or creates a view and assigns it to the
 view
 property.
 If the view controller has an associated nib file, this method loads the view from the nib file. A view controller has an associated nib file if the
 nibName
 property returns a non-nil value, which occurs if the view controller was instantiated from a storyboard, if you explicitly assigned it a nib file using the
 initWithNibName:bundle:
 method, or if iOS finds a nib file in the app bundle with a name based on the view controller's class name. If the view controller does not have an associated nib file, this method creates a plain
 UIView
 object instead.
 If you use Interface Builder to create your views and initialize the view controller, you must not override this method.*/


- (void)loadViewIfNeeded NS_AVAILABLE_IOS(9_0); // Loads the view controller's view if it has not already been set.
@property(nullable, nonatomic, readonly, strong) UIView *viewIfLoaded NS_AVAILABLE_IOS(9_0); // Returns the view controller's view if loaded, nil if not.

- (void)viewWillUnload NS_DEPRECATED_IOS(5_0,6_0) __TVOS_PROHIBITED;
- (void)viewDidUnload NS_DEPRECATED_IOS(3_0,6_0) __TVOS_PROHIBITED; // Called after the view controller's view is released and set to nil. For example, a memory warning which causes the view to be purged. Not invoked as a result of -dealloc.

- (void)viewDidLoad; // Called after the view has been loaded. For view controllers created in code, this is after -loadView. For view controllers unarchived from a nib, this is after the view is set.
//在初始化 instantiation 和 outlet-setting 后，viewDidLoad 就会被调用。
//但是要记住不要在 viewDidLoad 里设置跟 view 的几何特性相关的东西，比如 bounds。在这里，你还无法知道你的屏幕是 iPhone-5 还是 iPhone-4 或者 iPad。view 只会 load 一次，但是可能会 appear & disappear 很多次，所以在这里适合做一次性初始化的工作。
//说到这里，就提一句，在 Navigation Stack 中，一个个的 View Controller 被压栈或弹出栈，如果一个 View Controller 已经在栈中，它上面的别的 View Controller 被弹出，等它到栈顶的时候 viewDidLoad 是不会被调用的；如果它被弹出栈，下一次再被压栈的时候，viewDidLoad 会被调用。所以我们可以看到在 Navigation Stack 中新压入栈的 View Controller 会被 load，弹出栈的 View Controller 会被 dealloc。
//简单讲，第二步，就是viewDidLoad


#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly, getter=isViewLoaded) BOOL viewLoaded NS_AVAILABLE_IOS(3_0);
#else
- (BOOL)isViewLoaded NS_AVAILABLE_IOS(3_0);
#endif

@property(nullable, nonatomic, readonly, copy) NSString *nibName;     // The name of the nib to be loaded to instantiate the view.
@property(nullable, nonatomic, readonly, strong) NSBundle *nibBundle; // The bundle from which to load the nib.
@property(nullable, nonatomic, readonly, strong) UIStoryboard *storyboard NS_AVAILABLE_IOS(5_0);

- (void)performSegueWithIdentifier:(NSString *)identifier sender:(nullable id)sender NS_AVAILABLE_IOS(5_0);
- (BOOL)shouldPerformSegueWithIdentifier:(NSString *)identifier sender:(nullable id)sender NS_AVAILABLE_IOS(6_0); // Invoked immediately prior to initiating a segue. Return NO to prevent the segue from firing. The default implementation returns YES. This method is not invoked when -performSegueWithIdentifier:sender: is used.

// In a storyboard-based application, you will often want to do a little preparation before navigation
// Get the new view controller using [segue destinationViewController].
// Pass the selected object to the new view controller.
// 用SB的segue跳转时，需要用到这个方法
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(nullable id)sender NS_AVAILABLE_IOS(5_0);

// View controllers will receive this message during segue unwinding. The default implementation returns the result of -respondsToSelector: - controllers can override this to perform any ancillary checks, if necessary.
- (BOOL)canPerformUnwindSegueAction:(SEL)action fromViewController:(UIViewController *)fromViewController withSender:(id)sender NS_AVAILABLE_IOS(6_0);

// Returns a subset of the receiver's childViewControllers in the order they should be searched for an unwind destination.
// The default implementation first sends itself -childViewControllerContainingSegueSource:, then returns a copy of its childViewControllers array excluding that object. A custom container view controller can override this method to affect the order in which its children are searched, or to modify the result of the default implementation.
// For compatibility, if a view controller overrides the deprecated -viewControllerForUnwindSegueAction:fromViewController:sender: method, but does not override this method, it will receive the deprecated method instead of this method.
// To affect this view controller's eligibility as an unwind destination, override -canPerformUnwindSegueAction:fromViewController:withSender: instead.
- (NSArray<UIViewController *> *)allowedChildViewControllersForUnwindingFromSource:(UIStoryboardUnwindSegueSource *)source NS_AVAILABLE_IOS(9_0);

// Returns the child view controller that contains the provided segue source.
// Custom container view controllers should call this method from their implementation of -allowedChildViewControllersForUnwindingFromSource: to exclude the result from the returned array, as well as to determine the order of the returned array's contents.
// Do not try to re-implement or override this method; it takes special care to handle situations such as unwinding from a modally-presented view controller.
- (nullable UIViewController *)childViewControllerContainingSegueSource:(UIStoryboardUnwindSegueSource *)source NS_AVAILABLE_IOS(9_0);

// Deprecated. Returns a direct child of the receiver that responds YES to -canPerformUnwindSegueAction:fromViewController:withSender:, or self if no children respond YES but the receiver itself does. If this method has been overridden, UIViewController's implementation does not consult child view controllers at all, and skips straight to sending -canPerformUnwindSegueAction:... to self.
// Applications targeting iOS 9 or later should not override this method. Applications can instead override -allowedChildViewControllersForUnwindingFromSource: to guide UIKit’s search for a descendant view controller that returns YES from -canPerformUnwindSegueAction:fromViewController:withSender:.
- (nullable UIViewController *)viewControllerForUnwindSegueAction:(SEL)action fromViewController:(UIViewController *)fromViewController withSender:(nullable id)sender NS_DEPRECATED_IOS(6_0, 9_0);

// Custom container view controllers should override this method to modify themselves as part of an ongoing unwind segue. The subsequentVC is the parent, child, or presented view controller closest to the receiver in the direction of the segue's destinationViewController. For example, UINavigationController's implementation of this method will pop any necessary view controllers to reveal the subsequentVC.
- (void)unwindForSegue:(UIStoryboardSegue *)unwindSegue towardsViewController:(UIViewController *)subsequentVC NS_AVAILABLE_IOS(9_0);

// Deprecated. This method is only used for unwind segues whose destination view controller has been returned by an override of the deprecated method -viewControllerForUnwindSegueAction:fromViewController:withSender:. In that case, UIKit will choose a view controller to act as the “executor” of the unwind. If the destination view controller is being modally presented, the destination view controller itself is the executor. Otherwise, the destination view controller’s parent view controller is the executor. If the executor overrides this method, UIKit will ignore the Custom Class specified in Interface Builder and instead call this method on the executor to obtain a segue that can perform the unwind.
// The returned segue object must be able to perform all steps necessary to unwind, including dismissing any intermediate modal presentations or popping any necessary navigation items.
// Applications targeting iOS 9 or later should not override this method. Custom container view controllers should instead override -unwindForSegue:towardsViewController: to modify their local state as part of a UIKit-generated incremental unwind segue.
- (nullable UIStoryboardSegue *)segueForUnwindingToViewController:(UIViewController *)toViewController fromViewController:(UIViewController *)fromViewController identifier:(nullable NSString *)identifier NS_DEPRECATED_IOS(6_0, 9_0);

- (void)viewWillAppear:(BOOL)animated;    // Called when the view is about to made visible. Default does nothing
- (void)viewDidAppear:(BOOL)animated;     // Called when the view has been fully transitioned onto the screen. Default does nothing
- (void)viewWillDisappear:(BOOL)animated; // Called when the view is dismissed, covered or otherwise hidden. Default does nothing
- (void)viewDidDisappear:(BOOL)animated;  // Called after the view was dismissed, covered or otherwise hidden. Default does nothing

//在vc的view属性的layoutSubviews之前调用
// Called just before the view controller's view's layoutSubviews method is invoked. Subclasses can implement as necessary. The default is a nop.
- (void)viewWillLayoutSubviews NS_AVAILABLE_IOS(5_0);

//在vc的view属性的layoutSubviews之后调用
// Called just after the view controller's view's layoutSubviews method is invoked. Subclasses can implement as necessary. The default is a nop.
- (void)viewDidLayoutSubviews NS_AVAILABLE_IOS(5_0);

@property(nullable, nonatomic,copy) NSString *title;  // ViewController的名字，起到标识作用,Localized title for use by a parent controller.

- (void)didReceiveMemoryWarning; // Called when the parent application receives a memory warning. On iOS 6.0 it will no longer clear the view by default.

/*
  If this view controller is a child of a containing view controller (e.g. a navigation controller or tab bar
  controller,) this is the containing view controller.  Note that as of 5.0 this no longer will return the
  presenting view controller.
*/
@property(nullable,nonatomic,weak,readonly) UIViewController *parentViewController;

// This property has been replaced by presentedViewController.
@property(nullable, nonatomic,readonly) UIViewController *modalViewController NS_DEPRECATED_IOS(2_0, 6_0) __TVOS_PROHIBITED;

// The view controller that was presented by this view controller or its nearest ancestor.
@property(nullable, nonatomic,readonly) UIViewController *presentedViewController  NS_AVAILABLE_IOS(5_0);

// The view controller that presented this view controller (or its farthest ancestor.)
@property(nullable, nonatomic,readonly) UIViewController *presentingViewController NS_AVAILABLE_IOS(5_0);

/*
  Determines which parent view controller's view should be presented over for presentations of type
  UIModalPresentationCurrentContext.  If no ancestor view controller has this flag set, then the presenter
  will be the root view controller.
*/
@property(nonatomic,assign) BOOL definesPresentationContext NS_AVAILABLE_IOS(5_0);

// A controller that defines the presentation context can also specify the modal transition style if this property is true.
@property(nonatomic,assign) BOOL providesPresentationContextTransitionStyle NS_AVAILABLE_IOS(5_0);

// If YES, when this view controller becomes visible and focusable, focus will be automatically restored to the item that was last focused. For example, when an item in this view controller is focused, and then another view controller is presented and dismissed, the original item will become focused again. Defaults to YES.
@property (nonatomic) BOOL restoresFocusAfterTransition NS_AVAILABLE_IOS(10_0);

/*
  These four methods can be used in a view controller's appearance callbacks to determine if it is being
  presented, dismissed, or added or removed as a child view controller. For example, a view controller can
  check if it is disappearing because it was dismissed or popped by asking itself in its viewWillDisappear:
  method by checking the expression ([self isBeingDismissed] || [self isMovingFromParentViewController]).
*/

#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly, getter=isBeingPresented) BOOL beingPresented NS_AVAILABLE_IOS(5_0);
@property(nonatomic, readonly, getter=isBeingDismissed) BOOL beingDismissed NS_AVAILABLE_IOS(5_0);

@property(nonatomic, readonly, getter=isMovingToParentViewController) BOOL movingToParentViewController NS_AVAILABLE_IOS(5_0);
@property(nonatomic, readonly, getter=isMovingFromParentViewController) BOOL movingFromParentViewController NS_AVAILABLE_IOS(5_0);
#else
- (BOOL)isBeingPresented NS_AVAILABLE_IOS(5_0);
- (BOOL)isBeingDismissed NS_AVAILABLE_IOS(5_0);

- (BOOL)isMovingToParentViewController NS_AVAILABLE_IOS(5_0);
- (BOOL)isMovingFromParentViewController NS_AVAILABLE_IOS(5_0);
#endif

/*
  The next two methods are replacements for presentModalViewController:animated and
  dismissModalViewControllerAnimated: The completion handler, if provided, will be invoked after the presented
  controllers viewDidAppear: callback is invoked.
*/
- (void)presentViewController:(UIViewController *)viewControllerToPresent animated: (BOOL)flag completion:(void (^ __nullable)(void))completion NS_AVAILABLE_IOS(5_0);
// The completion handler, if provided, will be invoked after the dismissed controller's viewDidDisappear: callback is invoked.
- (void)dismissViewControllerAnimated: (BOOL)flag completion: (void (^ __nullable)(void))completion NS_AVAILABLE_IOS(5_0);

// Display another view controller as a modal child. Uses a vertical sheet transition if animated.This method has been replaced by presentViewController:animated:completion:
- (void)presentModalViewController:(UIViewController *)modalViewController animated:(BOOL)animated NS_DEPRECATED_IOS(2_0, 6_0) __TVOS_PROHIBITED;

// Dismiss the current modal child. Uses a vertical sheet transition if animated. This method has been replaced by dismissViewControllerAnimated:completion:
- (void)dismissModalViewControllerAnimated:(BOOL)animated NS_DEPRECATED_IOS(2_0, 6_0) __TVOS_PROHIBITED;

/*
  Defines the transition style that will be used for this view controller when it is presented modally. Set
  this property on the view controller to be presented, not the presenter.  Defaults to
  UIModalTransitionStyleCoverVertical.
*/
@property(nonatomic,assign) UIModalTransitionStyle modalTransitionStyle NS_AVAILABLE_IOS(3_0);
@property(nonatomic,assign) UIModalPresentationStyle modalPresentationStyle NS_AVAILABLE_IOS(3_2);
// This controls whether this view controller takes over control of the status bar's appearance when presented non-full screen on another view controller. Defaults to NO.
@property(nonatomic,assign) BOOL modalPresentationCapturesStatusBarAppearance NS_AVAILABLE_IOS(7_0) __TVOS_PROHIBITED;

// Presentation modes may keep the keyboard visible when not required. Default implementation affects UIModalPresentationFormSheet visibility.
#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly) BOOL disablesAutomaticKeyboardDismissal NS_AVAILABLE_IOS(4_3);
#else
- (BOOL)disablesAutomaticKeyboardDismissal NS_AVAILABLE_IOS(4_3);
#endif

@property(nonatomic,assign) BOOL wantsFullScreenLayout NS_DEPRECATED_IOS(3_0, 7_0) __TVOS_PROHIBITED; // Deprecated in 7_0, Replaced by the following:

@property(nonatomic,assign) UIRectEdge edgesForExtendedLayout NS_AVAILABLE_IOS(7_0); // Defaults to UIRectEdgeAll
@property(nonatomic,assign) BOOL extendedLayoutIncludesOpaqueBars NS_AVAILABLE_IOS(7_0); // Defaults to NO, but bars are translucent by default on 7_0.  
@property(nonatomic,assign) BOOL automaticallyAdjustsScrollViewInsets API_DEPRECATED_WITH_REPLACEMENT("Use UIScrollView's contentInsetAdjustmentBehavior instead", ios(7.0,11.0),tvos(7.0,11.0)); // Defaults to YES

/* The preferredContentSize is used for any container laying out a child view controller.
 */
@property (nonatomic) CGSize preferredContentSize NS_AVAILABLE_IOS(7_0);

//Status Bar
// These methods control the attributes of the status bar when this view controller is shown. They can be overridden in view controller subclasses to return the desired status bar attributes.
#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly) UIStatusBarStyle preferredStatusBarStyle NS_AVAILABLE_IOS(7_0) __TVOS_PROHIBITED; // Defaults to UIStatusBarStyleDefault
@property(nonatomic, readonly) BOOL prefersStatusBarHidden NS_AVAILABLE_IOS(7_0) __TVOS_PROHIBITED; // Defaults to NO
// Override to return the type of animation that should be used for status bar changes for this view controller. This currently only affects changes to prefersStatusBarHidden.
@property(nonatomic, readonly) UIStatusBarAnimation preferredStatusBarUpdateAnimation NS_AVAILABLE_IOS(7_0) __TVOS_PROHIBITED; // Defaults to UIStatusBarAnimationFade
#else
//样式
- (UIStatusBarStyle)preferredStatusBarStyle NS_AVAILABLE_IOS(7_0) __TVOS_PROHIBITED; // Defaults to UIStatusBarStyleDefault
//是否显示
- (BOOL)prefersStatusBarHidden NS_AVAILABLE_IOS(7_0) __TVOS_PROHIBITED; // Defaults to NO
// Override to return the type of animation that should be used for status bar changes for this view controller. This currently only affects changes to prefersStatusBarHidden.
//动画
- (UIStatusBarAnimation)preferredStatusBarUpdateAnimation NS_AVAILABLE_IOS(7_0) __TVOS_PROHIBITED; // Defaults to UIStatusBarAnimationFade
#endif

//当status bar发生改变时，需要调用这个函数来执行更新
// This should be called whenever the return values for the view controller's status bar attributes have changed. If it is called from within an animation block, the changes will be animated along with the rest of the animation block.
//我们一般是在切换控制器时修改状态栏, 但有时我们也可能在同一个控制器内对状态栏进行操作, 因此我们可以手动调用如下方法让控制器重新调用状态栏管理方法以及时更新状态栏
//如果在Block动画中调用如上方法, 在更新状态栏时会有动画效果
- (void)setNeedsStatusBarAppearanceUpdate NS_AVAILABLE_IOS(7_0) __TVOS_PROHIBITED;



/* This method returns either itself or the nearest ancestor that can perform the given action and, if applicable, has overridden UIViewController's default implementation of the action method. View controllers can return NO from canPerformAction:withSender: to opt out of being a target for a given action. */
- (nullable UIViewController *)targetViewControllerForAction:(SEL)action sender:(nullable id)sender NS_AVAILABLE_IOS(8_0);

/* This method will show a view controller appropriately for the current size-class environment. It's implementation calls
 `[self targetViewControllerForAction:sender:]` first and redirects accordingly if the return value is not `self`, otherwise it will present the vc. */
- (void)showViewController:(UIViewController *)vc sender:(nullable id)sender NS_AVAILABLE_IOS(8_0);

/* This method will show a view controller within the semantic "detail" UI associated with the current size-class environment. It's implementation calls  `[self targetViewControllerForAction:sender:]` first and redirects accordingly if the return value is not `self`, otherwise it will present the vc.  */
- (void)showDetailViewController:(UIViewController *)vc sender:(nullable id)sender NS_AVAILABLE_IOS(8_0);

// Subclasses may override if they prefer a user interface style other than the one preferred by the application.
@property (nonatomic, readonly) UIUserInterfaceStyle preferredUserInterfaceStyle API_AVAILABLE(tvos(11.0)) API_UNAVAILABLE(ios, watchos); // Defaults to UIUserInterfaceStyleUnspecified

// This should be called whenever the view controller's preferredUserInterfaceStyle changes.
- (void)setNeedsUserInterfaceAppearanceUpdate API_AVAILABLE(tvos(11.0)) API_UNAVAILABLE(ios, watchos);

@end

//屏幕旋转(属性和设置方法)
// To make it more convenient for applications to adopt rotation, a view controller may implement the below methods. Your UIWindow's frame should use [UIScreen mainScreen].bounds as its frame.
@interface UIViewController (UIViewControllerRotation)

// call this method when your return value from shouldAutorotateToInterfaceOrientation: changes
// if the current interface orientation does not match the current device orientation, a rotation may occur provided all relevant view controllers now return YES from shouldAutorotateToInterfaceOrientation:
+ (void)attemptRotationToDeviceOrientation NS_AVAILABLE_IOS(5_0) __TVOS_PROHIBITED;

// Applications should use supportedInterfaceOrientations and/or shouldAutorotate..
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation NS_DEPRECATED_IOS(2_0, 6_0) __TVOS_PROHIBITED;

// New Autorotation support.
#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly) BOOL shouldAutorotate NS_AVAILABLE_IOS(6_0) __TVOS_PROHIBITED; //是否支持旋转
@property(nonatomic, readonly) UIInterfaceOrientationMask supportedInterfaceOrientations NS_AVAILABLE_IOS(6_0) __TVOS_PROHIBITED; //支持的方向

// Returns interface orientation masks.
//http://sxcheen.com/2016/04/29/iOS-Orientations/
//如果当前ViewController是通过全屏的Presentation方式展现出来的（presentViewController:animated:completion:），还可以指定优先呈现屏幕方向。即使它之后也会根据设备方向旋转到所支持的屏幕方向。默认返回当前状态栏的方向。
@property(nonatomic, readonly) UIInterfaceOrientation preferredInterfaceOrientationForPresentation NS_AVAILABLE_IOS(6_0) __TVOS_PROHIBITED;//可以理解为，现在呈现出来的方向
#else
- (BOOL)shouldAutorotate NS_AVAILABLE_IOS(6_0) __TVOS_PROHIBITED;
- (UIInterfaceOrientationMask)supportedInterfaceOrientations NS_AVAILABLE_IOS(6_0) __TVOS_PROHIBITED;
// Returns interface orientation masks.
- (UIInterfaceOrientation)preferredInterfaceOrientationForPresentation NS_AVAILABLE_IOS(6_0) __TVOS_PROHIBITED; //可以设置，这样往往会干扰系统工作
#endif

// The rotating header and footer views will slide out during the rotation and back in once it has completed.
- (nullable UIView *)rotatingHeaderView NS_DEPRECATED_IOS(2_0,8_0, "Header views are animated along with the rest of the view hierarchy") __TVOS_PROHIBITED;     // Must be in the view hierarchy. Default returns nil.
- (nullable UIView *)rotatingFooterView NS_DEPRECATED_IOS(2_0,8_0, "Footer views are animated along with the rest of the view hierarchy") __TVOS_PROHIBITED;     // Must be in the view hierarchy. Default returns nil.

@property(nonatomic,readonly) UIInterfaceOrientation interfaceOrientation NS_DEPRECATED_IOS(2_0,8_0) __TVOS_PROHIBITED;

// Notifies when rotation begins, reaches halfway point and ends.
- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration NS_DEPRECATED_IOS(2_0,8_0, "Implement viewWillTransitionToSize:withTransitionCoordinator: instead") __TVOS_PROHIBITED;
- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation NS_DEPRECATED_IOS(2_0,8_0) __TVOS_PROHIBITED;

- (void)willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration NS_DEPRECATED_IOS(3_0,8_0, "Implement viewWillTransitionToSize:withTransitionCoordinator: instead") __TVOS_PROHIBITED;

- (void)willAnimateFirstHalfOfRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration NS_DEPRECATED_IOS(2_0, 5_0) __TVOS_PROHIBITED;
- (void)didAnimateFirstHalfOfRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation NS_DEPRECATED_IOS(2_0, 5_0) __TVOS_PROHIBITED; // The rotating header and footer views are offscreen.
- (void)willAnimateSecondHalfOfRotationFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation duration:(NSTimeInterval)duration NS_DEPRECATED_IOS(2_0, 5_0) __TVOS_PROHIBITED; // A this point, our view orientation is set to the new orientation.

@end

// Many view controllers have a view that may be in an editing state or not- for example, a UITableView.  These view
// controllers can track the editing state, and generate an Edit|Done button to be used in a navigation bar.
@interface UIViewController (UIViewControllerEditing)

@property(nonatomic,getter=isEditing) BOOL editing;
- (void)setEditing:(BOOL)editing animated:(BOOL)animated; // Updates the appearance of the Edit|Done button item as necessary. Clients who override it must call super first.

#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly) UIBarButtonItem *editButtonItem; // Return an Edit|Done button that can be used as a navigation item's custom view. Default action toggles the editing state with animation.
#else
- (UIBarButtonItem *)editButtonItem; // Return an Edit|Done button that can be used as a navigation item's custom view. Default action toggles the editing state with animation.
#endif

@end

@interface UIViewController (UISearchDisplayControllerSupport)

@property(nullable, nonatomic, readonly, strong) UISearchDisplayController *searchDisplayController NS_DEPRECATED_IOS(3_0,8_0) __TVOS_PROHIBITED;

@end


/*
  This exception is raised when a child view controller's view is added into the view hierarchy and the first
  superview of the child view controller's view that has a view controller is NOT the child view controller's
  parent.
*/
UIKIT_EXTERN NSExceptionName const UIViewControllerHierarchyInconsistencyException NS_AVAILABLE_IOS(5_0);

/*
  The methods in the UIContainerViewControllerProtectedMethods and the UIContainerViewControllerCallbacks
  categories typically should only be called by subclasses which are implementing new container view
  controllers. They may be overridden but must call super.
*/
@interface UIViewController (UIContainerViewControllerProtectedMethods)

// An array of children view controllers. This array does not include any presented view controllers.
@property(nonatomic,readonly) NSArray<__kindof UIViewController *> *childViewControllers NS_AVAILABLE_IOS(5_0);

/*
  If the child controller has a different parent controller, it will first be removed from its current parent
  by calling removeFromParentViewController. If this method is overridden then the super implementation must
  be called.
*/
- (void)addChildViewController:(UIViewController *)childController NS_AVAILABLE_IOS(5_0);

/*
  Removes the the receiver from its parent's children controllers array. If this method is overridden then
  the super implementation must be called.
*/
- (void)removeFromParentViewController NS_AVAILABLE_IOS(5_0);

/*
  This method can be used to transition between sibling child view controllers. The receiver of this method is
  their common parent view controller. (Use [UIViewController addChildViewController:] to create the
  parent/child relationship.) This method will add the toViewController's view to the superview of the
  fromViewController's view and the fromViewController's view will be removed from its superview after the
  transition completes. It is important to allow this method to add and remove the views. The arguments to
  this method are the same as those defined by UIView's block animation API. This method will fail with an
  NSInvalidArgumentException if the parent view controllers are not the same as the receiver, or if the
  receiver explicitly forwards its appearance and rotation callbacks to its children. Finally, the receiver
  should not be a subclass of an iOS container view controller. Note also that it is possible to use the
  UIView APIs directly. If they are used it is important to ensure that the toViewController's view is added
  to the visible view hierarchy while the fromViewController's view is removed.
*/
- (void)transitionFromViewController:(UIViewController *)fromViewController toViewController:(UIViewController *)toViewController duration:(NSTimeInterval)duration options:(UIViewAnimationOptions)options animations:(void (^ __nullable)(void))animations completion:(void (^ __nullable)(BOOL finished))completion NS_AVAILABLE_IOS(5_0);

// If a custom container controller manually forwards its appearance callbacks, then rather than calling
// viewWillAppear:, viewDidAppear: viewWillDisappear:, or viewDidDisappear: on the children these methods
// should be used instead. This will ensure that descendent child controllers appearance methods will be
// invoked. It also enables more complex custom transitions to be implemented since the appearance callbacks are
// now tied to the final matching invocation of endAppearanceTransition.
- (void)beginAppearanceTransition:(BOOL)isAppearing animated:(BOOL)animated __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
- (void)endAppearanceTransition __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);

////http://www.jianshu.com/p/006c2d663d2d
//重载导航控制器Navigation Controller中如下两个方法, 根据栈顶控制器View Controller对状态栏的管理结果来管理状态栏
//记得要在，相应viewcontroller的viewwillappear中调用这个方法，setNeedsUpdatedStatusBarAttributes，保险，也能随时更改显示的外观
// Override to return a child view controller or nil. If non-nil, that view controller's status bar appearance attributes will be used. If nil, self is used. Whenever the return values from these methods change, -setNeedsUpdatedStatusBarAttributes should be called.
#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly, nullable) UIViewController *childViewControllerForStatusBarStyle NS_AVAILABLE_IOS(7_0) __TVOS_PROHIBITED;
@property(nonatomic, readonly, nullable) UIViewController *childViewControllerForStatusBarHidden NS_AVAILABLE_IOS(7_0) __TVOS_PROHIBITED;
#else
- (nullable UIViewController *)childViewControllerForStatusBarStyle NS_AVAILABLE_IOS(7_0) __TVOS_PROHIBITED;
- (nullable UIViewController *)childViewControllerForStatusBarHidden NS_AVAILABLE_IOS(7_0) __TVOS_PROHIBITED;
#endif

// Call to modify the trait collection for child view controllers.
- (void)setOverrideTraitCollection:(nullable UITraitCollection *)collection forChildViewController:(UIViewController *)childViewController NS_AVAILABLE_IOS(8_0);
- (nullable UITraitCollection *)overrideTraitCollectionForChildViewController:(UIViewController *)childViewController NS_AVAILABLE_IOS(8_0);

// Override to return a child view controller or nil. If non-nil, that view controller's preferred user interface style will be used. If nil, self is used. Whenever the preferredUserInterfaceStyle for a view controller has changed setNeedsUserInterfaceAppearanceUpdate should be called.
@property (nonatomic, readonly, nullable) UIViewController *childViewControllerForUserInterfaceStyle API_AVAILABLE(tvos(11.0)) API_UNAVAILABLE(ios, watchos);

@end

@interface UIViewController (UIContainerViewControllerCallbacks)

/*
  This method is consulted to determine if a view controller manually forwards its containment callbacks to
  any children view controllers. Subclasses of UIViewController that implement containment logic may override
  this method. The default implementation returns YES. If it is overridden and returns NO, then the subclass is
  responsible for forwarding the following methods as appropriate - viewWillAppear: viewDidAppear: viewWillDisappear:
  viewDidDisappear: willRotateToInterfaceOrientation:duration:
  willAnimateRotationToInterfaceOrientation:duration: didRotateFromInterfaceOrientation:
*/

- (BOOL)automaticallyForwardAppearanceAndRotationMethodsToChildViewControllers NS_DEPRECATED_IOS(5_0,6_0) __TVOS_PROHIBITED;
- (BOOL)shouldAutomaticallyForwardRotationMethods NS_DEPRECATED_IOS(6_0,8_0, "Manually forward viewWillTransitionToSize:withTransitionCoordinator: if necessary") __TVOS_PROHIBITED;

#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly) BOOL shouldAutomaticallyForwardAppearanceMethods NS_AVAILABLE_IOS(6_0);
#else
- (BOOL)shouldAutomaticallyForwardAppearanceMethods NS_AVAILABLE_IOS(6_0);
#endif


/*
  These two methods are public for container subclasses to call when transitioning between child
  controllers. If they are overridden, the overrides should ensure to call the super. The parent argument in
  both of these methods is nil when a child is being removed from its parent; otherwise it is equal to the new
  parent view controller.

  addChildViewController: will call [child willMoveToParentViewController:self] before adding the
  child. However, it will not call didMoveToParentViewController:. It is expected that a container view
  controller subclass will make this call after a transition to the new child has completed or, in the
  case of no transition, immediately after the call to addChildViewController:. Similarly,
  removeFromParentViewController does not call [self willMoveToParentViewController:nil] before removing the
  child. This is also the responsibilty of the container subclass. Container subclasses will typically define
  a method that transitions to a new child by first calling addChildViewController:, then executing a
  transition which will add the new child's view into the view hierarchy of its parent, and finally will call
  didMoveToParentViewController:. Similarly, subclasses will typically define a method that removes a child in
  the reverse manner by first calling [child willMoveToParentViewController:nil].
*/
- (void)willMoveToParentViewController:(nullable UIViewController *)parent NS_AVAILABLE_IOS(5_0);
- (void)didMoveToParentViewController:(nullable UIViewController *)parent NS_AVAILABLE_IOS(5_0);

@end

@interface UIViewController (UIStateRestoration) <UIStateRestoring>
@property (nullable, nonatomic, copy) NSString *restorationIdentifier NS_AVAILABLE_IOS(6_0);
@property (nullable, nonatomic, readwrite, assign) Class<UIViewControllerRestoration> restorationClass NS_AVAILABLE_IOS(6_0);
- (void) encodeRestorableStateWithCoder:(NSCoder *)coder NS_AVAILABLE_IOS(6_0);
- (void) decodeRestorableStateWithCoder:(NSCoder *)coder NS_AVAILABLE_IOS(6_0);
- (void) applicationFinishedRestoringState NS_AVAILABLE_IOS(7_0);
@end

@interface UIViewController (UIConstraintBasedLayoutCoreMethods)
/* Base implementation sends -updateConstraints to the view.
    When a view has a view controller, this message is sent to the view controller during 
     the autolayout updateConstraints pass in lieu of sending updateConstraints directly
     to the view.
    You may override this method in a UIViewController subclass for updating custom 
     constraints instead of subclassing your view and overriding -[UIView updateConstraints].
    Overrides must call super or send -updateConstraints to the view.
 */
- (void)updateViewConstraints NS_AVAILABLE_IOS(6_0);
@end

@protocol UIViewControllerTransitioningDelegate;

@interface UIViewController(UIViewControllerTransitioning)

@property (nullable, nonatomic, weak) id <UIViewControllerTransitioningDelegate> transitioningDelegate NS_AVAILABLE_IOS(7_0);

@end

@interface UIViewController (UILayoutSupport)
// These objects may be used as layout items in the NSLayoutConstraint API
@property(nonatomic,readonly,strong) id<UILayoutSupport> topLayoutGuide API_DEPRECATED_WITH_REPLACEMENT("-[UIView safeAreaLayoutGuide]", ios(7.0,11.0), tvos(7.0,11.0));
@property(nonatomic,readonly,strong) id<UILayoutSupport> bottomLayoutGuide API_DEPRECATED_WITH_REPLACEMENT("-[UIView safeAreaLayoutGuide]", ios(7.0,11.0), tvos(7.0,11.0));

/* Custom container UIViewController subclasses can use this property to add to the overlay
 that UIViewController calculates for the safeAreaInsets for contained view controllers.
 */
@property(nonatomic) UIEdgeInsets additionalSafeAreaInsets API_AVAILABLE(ios(11.0), tvos(11.0));

/* Minimum layoutMargins for the view determined by the view controller from context and hardware information.
 The view controller's view will respect these minimums unless viewRespectsSystemMinimumLayoutMargins
 (which defaults to YES) is set to NO.
 */
@property(nonatomic,readonly) NSDirectionalEdgeInsets systemMinimumLayoutMargins API_AVAILABLE(ios(11.0), tvos(11.0));

/* Default YES. The return value of the view's layoutMargins and directionalLayoutMargins properties will have
 values no smaller than the systemMinimumLayoutMargins. Set to NO for full customizability of the view's
 layoutMargins.
 */
@property(nonatomic) BOOL viewRespectsSystemMinimumLayoutMargins API_AVAILABLE(ios(11.0), tvos(11.0));

- (void)viewLayoutMarginsDidChange NS_REQUIRES_SUPER API_AVAILABLE(ios(11.0), tvos(11.0));
- (void)viewSafeAreaInsetsDidChange NS_REQUIRES_SUPER API_AVAILABLE(ios(11.0), tvos(11.0));

@end

@interface UIViewController (UIKeyCommand)

- (void)addKeyCommand:(UIKeyCommand *)keyCommand NS_AVAILABLE_IOS(9_0);
- (void)removeKeyCommand:(UIKeyCommand *)keyCommand NS_AVAILABLE_IOS(9_0);

@end

@class NSExtensionContext;

@interface UIViewController(NSExtensionAdditions) <NSExtensionRequestHandling>

// Returns the extension context. Also acts as a convenience method for a view controller to check if it participating in an extension request.
@property (nullable, nonatomic,readonly,strong) NSExtensionContext *extensionContext NS_AVAILABLE_IOS(8_0);

@end

@class UIPresentationController, UIPopoverPresentationController;

@interface UIViewController (UIAdaptivePresentations)
@property (nullable, nonatomic,readonly) UIPresentationController *presentationController NS_AVAILABLE_IOS(8_0);
@property (nullable, nonatomic,readonly) UIPopoverPresentationController *popoverPresentationController NS_AVAILABLE_IOS(8_0);
@end


@protocol UIViewControllerPreviewingDelegate;

@protocol UIViewControllerPreviewing <NSObject>

// This gesture can be used to cause the previewing presentation to wait until one of your gestures fails or to allow simultaneous recognition during the initial phase of the preview presentation.
@property (nonatomic, readonly) UIGestureRecognizer *previewingGestureRecognizerForFailureRelationship NS_AVAILABLE_IOS(9_0);

@property (nonatomic, readonly) id<UIViewControllerPreviewingDelegate> delegate NS_AVAILABLE_IOS(9_0);
@property (nonatomic, readonly) UIView *sourceView NS_AVAILABLE_IOS(9_0);

// This rect will be set to the bounds of sourceView before each call to
// -previewingContext:viewControllerForLocation:

@property (nonatomic) CGRect sourceRect NS_AVAILABLE_IOS(9_0);

@end


NS_CLASS_AVAILABLE_IOS(9_0) @protocol UIViewControllerPreviewingDelegate <NSObject>

// If you return nil, a preview presentation will not be performed
- (nullable UIViewController *)previewingContext:(id <UIViewControllerPreviewing>)previewingContext viewControllerForLocation:(CGPoint)location NS_AVAILABLE_IOS(9_0);
- (void)previewingContext:(id <UIViewControllerPreviewing>)previewingContext commitViewController:(UIViewController *)viewControllerToCommit NS_AVAILABLE_IOS(9_0);

@end

@interface UIViewController (UIViewControllerPreviewingRegistration)

// Registers a view controller to participate with 3D Touch preview (peek) and commit (pop).
- (id <UIViewControllerPreviewing>)registerForPreviewingWithDelegate:(id<UIViewControllerPreviewingDelegate>)delegate sourceView:(UIView *)sourceView NS_AVAILABLE_IOS(9_0);
- (void)unregisterForPreviewingWithContext:(id <UIViewControllerPreviewing>)previewing NS_AVAILABLE_IOS(9_0);

@end

@interface UIViewController (UIScreenEdgesDeferringSystemGestures)

// Override to return a child view controller or nil. If non-nil, that view controller's screen edges deferring system gestures will be used. If nil, self is used. Whenever the return value changes, -setNeedsScreenEdgesDeferringSystemGesturesUpdate should be called.
- (nullable UIViewController *)childViewControllerForScreenEdgesDeferringSystemGestures API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos);

// Controls the application's preferred screen edges deferring system gestures when this view controller is shown. Default is UIRectEdgeNone.
- (UIRectEdge)preferredScreenEdgesDeferringSystemGestures API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos);

// This should be called whenever the return values for the view controller's screen edges deferring system gestures have changed.
- (void)setNeedsUpdateOfScreenEdgesDeferringSystemGestures API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos);

@end


@interface UIViewController (UIHomeIndicatorAutoHidden)

// Override to return a child view controller or nil. If non-nil, that view controller's home indicator auto-hiding will be used. If nil, self is used. Whenever the return value changes, -setNeedsHomeIndicatorAutoHiddenUpdate should be called.
- (nullable UIViewController *)childViewControllerForHomeIndicatorAutoHidden API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos);

// Controls the application's preferred home indicator auto-hiding when this view controller is shown.
- (BOOL)prefersHomeIndicatorAutoHidden API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos);

// This should be called whenever the return values for the view controller's home indicator auto-hiding have changed.
- (void)setNeedsUpdateOfHomeIndicatorAutoHidden API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos);

@end


@protocol UIPreviewActionItem;

@interface UIViewController ()

#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly) NSArray <id <UIPreviewActionItem>> *previewActionItems NS_AVAILABLE_IOS(9_0);
#else
- (NSArray <id <UIPreviewActionItem>> *)previewActionItems NS_AVAILABLE_IOS(9_0);
#endif

@end


NS_CLASS_AVAILABLE_IOS(9_0) @protocol UIPreviewActionItem <NSObject>
@property(nonatomic, copy, readonly) NSString *title;
@end

typedef NS_ENUM(NSInteger,UIPreviewActionStyle) {
    UIPreviewActionStyleDefault=0,
    UIPreviewActionStyleSelected,
    UIPreviewActionStyleDestructive,
} NS_ENUM_AVAILABLE_IOS(9_0);

NS_CLASS_AVAILABLE_IOS(9_0) @interface UIPreviewAction : NSObject <NSCopying,UIPreviewActionItem>

@property(nonatomic, copy, readonly) void (^handler)(id<UIPreviewActionItem> action, UIViewController *previewViewController);

+ (instancetype)actionWithTitle:(NSString *)title style:(UIPreviewActionStyle)style handler:(void (^)(UIPreviewAction *action, UIViewController *previewViewController))handler;

@end

NS_CLASS_AVAILABLE_IOS(9_0) @interface UIPreviewActionGroup : NSObject <NSCopying,UIPreviewActionItem>
+ (instancetype)actionGroupWithTitle:(NSString *)title style:(UIPreviewActionStyle)style actions:(NSArray<UIPreviewAction *> *)actions;
@end

NS_ASSUME_NONNULL_END
