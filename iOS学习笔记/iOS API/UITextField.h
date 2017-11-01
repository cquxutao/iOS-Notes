//
//  UITextField.h
//  UIKit
//
//  Copyright (c) 2005-2017 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIFont.h>
#import <UIKit/UIStringDrawing.h>
#import <UIKit/UITextDragging.h>
#import <UIKit/UITextDropping.h>
#import <UIKit/UITextInput.h>
#import <UIKit/UIContentSizeCategoryAdjusting.h>
#import <UIKit/UITextPasteConfigurationSupporting.h>

NS_ASSUME_NONNULL_BEGIN

@class UIImage, UIImageView, UILabel, UIColor, UIButton;
@class UITextFieldAtomBackgroundView;
@class UITextFieldBackgroundView;
@class UITextFieldBorderView;
@class UITextFieldLabel;
@class UITextInputTraits;
@class UITextSelectionView;
@class UITextInteractionAssistant;
@class UIPopoverController;
@protocol UITextFieldDelegate;
@protocol UITextSelecting;

typedef NS_ENUM(NSInteger, UITextBorderStyle) {
    UITextBorderStyleNone,
    UITextBorderStyleLine,
    UITextBorderStyleBezel,
    UITextBorderStyleRoundedRect
};

typedef NS_ENUM(NSInteger, UITextFieldViewMode) {
    UITextFieldViewModeNever,
    UITextFieldViewModeWhileEditing,
    UITextFieldViewModeUnlessEditing,
    UITextFieldViewModeAlways
};

typedef NS_ENUM(NSInteger, UITextFieldDidEndEditingReason) {
    UITextFieldDidEndEditingReasonCommitted,
    UITextFieldDidEndEditingReasonCancelled UIKIT_AVAILABLE_TVOS_ONLY(10_0)
} NS_ENUM_AVAILABLE_IOS(10_0);

NS_CLASS_AVAILABLE_IOS(2_0) @interface UITextField : UIControl <UITextInput, NSCoding, UIContentSizeCategoryAdjusting>

@property(nullable, nonatomic,copy)   NSString               *text;                 // default is nil
@property(nullable, nonatomic,copy)   NSAttributedString     *attributedText NS_AVAILABLE_IOS(6_0); // default is nil
@property(nullable, nonatomic,strong) UIColor                *textColor;            // default is nil. use opaque black
@property(nullable, nonatomic,strong) UIFont                 *font;                 // default is nil. use system font 12 pt
@property(nonatomic)        NSTextAlignment         textAlignment;        // default is NSLeftTextAlignment
@property(nonatomic)        UITextBorderStyle       borderStyle;          // default is UITextBorderStyleNone. If set to UITextBorderStyleRoundedRect, custom background images are ignored.
@property(nonatomic,copy)   NSDictionary<NSString *, id>           *defaultTextAttributes NS_AVAILABLE_IOS(7_0); // applies attributes to the full range of text. Unset attributes act like default values.

@property(nullable, nonatomic,copy)   NSString               *placeholder;          // default is nil. string is drawn 70% gray
@property(nullable, nonatomic,copy)   NSAttributedString     *attributedPlaceholder NS_AVAILABLE_IOS(6_0); // default is nil
@property(nonatomic)        BOOL                    clearsOnBeginEditing; // default is NO which moves cursor to location clicked. if YES, all text cleared
@property(nonatomic)        BOOL                    adjustsFontSizeToFitWidth; // default is NO. if YES, text will shrink to minFontSize along baseline
@property(nonatomic)        CGFloat                 minimumFontSize;      // default is 0.0. actual min may be pinned to something readable. used if adjustsFontSizeToFitWidth is YES
@property(nullable, nonatomic,weak)   id<UITextFieldDelegate> delegate;             // default is nil. weak reference
@property(nullable, nonatomic,strong) UIImage                *background;           // default is nil. draw in border rect. image should be stretchable
@property(nullable, nonatomic,strong) UIImage                *disabledBackground;   // default is nil. ignored if background not set. image should be stretchable

@property(nonatomic,readonly,getter=isEditing) BOOL editing;
@property(nonatomic) BOOL allowsEditingTextAttributes NS_AVAILABLE_IOS(6_0); // default is NO. allows editing text attributes with style operations and pasting rich text
@property(nullable, nonatomic,copy) NSDictionary<NSString *, id> *typingAttributes NS_AVAILABLE_IOS(6_0); // automatically resets when the selection changes


// You can supply custom views which are displayed at the left or right
// sides of the text field. Uses for such views could be to show an icon or
// a button to operate on the text in the field in an application-defined
// manner.
// 
// A very common use is to display a clear button on the right side of the
// text field, and a standard clear button is provided.

@property(nonatomic)        UITextFieldViewMode  clearButtonMode; // sets when the clear button shows up. default is UITextFieldViewModeNever

@property(nullable, nonatomic,strong) UIView              *leftView;        // e.g. magnifying glass
@property(nonatomic)        UITextFieldViewMode  leftViewMode;    // sets when the left view shows up. default is UITextFieldViewModeNever

@property(nullable, nonatomic,strong) UIView              *rightView;       // e.g. bookmarks button
@property(nonatomic)        UITextFieldViewMode  rightViewMode;   // sets when the right view shows up. default is UITextFieldViewModeNever

// drawing and positioning overrides

- (CGRect)borderRectForBounds:(CGRect)bounds;
- (CGRect)textRectForBounds:(CGRect)bounds;
- (CGRect)placeholderRectForBounds:(CGRect)bounds;
- (CGRect)editingRectForBounds:(CGRect)bounds;
- (CGRect)clearButtonRectForBounds:(CGRect)bounds;
- (CGRect)leftViewRectForBounds:(CGRect)bounds;
- (CGRect)rightViewRectForBounds:(CGRect)bounds;

- (void)drawTextInRect:(CGRect)rect;
- (void)drawPlaceholderInRect:(CGRect)rect;

// Presented when object becomes first responder.  If set to nil, reverts to following responder chain.  If
// set while first responder, will not take effect until reloadInputViews is called.
@property (nullable, readwrite, strong) UIView *inputView;             
@property (nullable, readwrite, strong) UIView *inputAccessoryView;

@property(nonatomic) BOOL clearsOnInsertion NS_AVAILABLE_IOS(6_0); // defaults to NO. if YES, the selection UI is hidden, and inserting text will replace the contents of the field. changing the selection will automatically set this to NO.

@end

#if TARGET_OS_IOS

@interface UITextField () <UITextDraggable, UITextDroppable, UITextPasteConfigurationSupporting>
@end

#endif

@interface UIView (UITextField)
- (BOOL)endEditing:(BOOL)force;    // use to make the view or any subview that is the first responder resign (optionally force)
@end

@protocol UITextFieldDelegate <NSObject>

@optional

//是否可以编辑,返回NO时，不可以编辑
- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField;        // return NO to disallow editing.,是否允许编辑

//该方法被触发时，意味着输入框可以编辑，已经进入了编辑状态
//这个不是用来实时获取值的函数，它只是在开始编辑时，才进行一次操作
- (void)textFieldDidBeginEditing:(UITextField *)textField;           // became first responder，变为第一响应者，多用于接收内容

//是否可以取消编辑状态，键盘是否可以回收
- (BOOL)textFieldShouldEndEditing:(UITextField *)textField;          // return YES to allow editing to stop and to resign first responder status. NO to disallow the editing session to end

//该方法被触发时，输入框已经结束编辑状态了
//如果是想，在结束的时候，获取内容，并展示，就用这个方法
- (void)textFieldDidEndEditing:(UITextField *)textField;             // may be called if forced even if shouldEndEditing returns NO (e.g. view removed from window) or endEditing:YES called

//不懂
- (void)textFieldDidEndEditing:(UITextField *)textField reason:(UITextFieldDidEndEditingReason)reason NS_AVAILABLE_IOS(10_0); // if implemented, called in place of textFieldDidEndEditing:

//当输入框内容发生变化时，就会触发这个方法，能够及时获取输入框最新的内容
//实时获取输入的内容
- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;   // return NO to not change text

//输入框询问是否可以清除内容，开始编辑以及点击清除按钮时触发
- (BOOL)textFieldShouldClear:(UITextField *)textField;               // called when clear button pressed. return NO to ignore (no notifications)

//点击return按钮时触发，经常用来回收键盘，取消编辑状态
- (BOOL)textFieldShouldReturn:(UITextField *)textField;              // called when 'return' key pressed. return NO to ignore.

@end

UIKIT_EXTERN NSNotificationName const UITextFieldTextDidBeginEditingNotification;
UIKIT_EXTERN NSNotificationName const UITextFieldTextDidEndEditingNotification;
UIKIT_EXTERN NSNotificationName const UITextFieldTextDidChangeNotification;

UIKIT_EXTERN NSString *const UITextFieldDidEndEditingReasonKey NS_AVAILABLE_IOS(10_0);

NS_ASSUME_NONNULL_END

