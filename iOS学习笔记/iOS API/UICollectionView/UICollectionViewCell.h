//
//  UICollectionViewCell.h
//  UIKit
//
//  Copyright (c) 2011-2017 Apple Inc. All rights reserved.
//

#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UICollectionView.h>

NS_ASSUME_NONNULL_BEGIN

@class UICollectionViewLayout;
@class UICollectionView;
@class UICollectionViewLayoutAttributes;
@class UILongPressGestureRecognizer;

typedef NS_ENUM(NSInteger, UICollectionViewCellDragState) {
    UICollectionViewCellDragStateNone,
    /* The cell is in the "lifting" state.
     */
    UICollectionViewCellDragStateLifting,
    
    /* A cell in the "dragging" state is left behind with a
     * "ghosted" appearance to denote where the drag
     * started from.
     */
    UICollectionViewCellDragStateDragging
} API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);

NS_CLASS_AVAILABLE_IOS(6_0) @interface UICollectionReusableView : UIView

@property (nonatomic, readonly, copy, nullable) NSString *reuseIdentifier;

// Override point.
// Called by the collection view before the instance is returned from the reuse queue.
// Subclassers must call super.
// Performs any clean up necessary to prepare the view for use again.
// 重用之前的一些清理工作
// When a view is dequeued for use, this method is called before the corresponding dequeue method returns the view to your code.
- (void)prepareForReuse;

// Classes that want to support custom layout attributes specific to a given UICollectionViewLayout subclass can apply them here.
// This allows the view to work in conjunction with a layout class that returns a custom subclass of UICollectionViewLayoutAttributes from -layoutAttributesForItem: or the corresponding layoutAttributesForHeader/Footer methods.
// -applyLayoutAttributes: is then called after the view is added to the collection view and just before the view is returned from the reuse queue.
// Note that -applyLayoutAttributes: is only called when attributes change, as defined by -isEqual:.
- (void)applyLayoutAttributes:(UICollectionViewLayoutAttributes *)layoutAttributes;

// Override these methods to provide custom UI for specific layouts.
- (void)willTransitionFromLayout:(UICollectionViewLayout *)oldLayout toLayout:(UICollectionViewLayout *)newLayout;
- (void)didTransitionFromLayout:(UICollectionViewLayout *)oldLayout toLayout:(UICollectionViewLayout *)newLayout;

//Gives the cell a chance to modify the attributes provided by the layout object.
//https://developer.apple.com/documentation/uikit/uicollectionreusableview/1620132-preferredlayoutattributesfitting?language=objc
- (UICollectionViewLayoutAttributes *)preferredLayoutAttributesFittingAttributes:(UICollectionViewLayoutAttributes *)layoutAttributes NS_AVAILABLE_IOS(8_0);

@end

NS_CLASS_AVAILABLE_IOS(6_0) @interface UICollectionViewCell : UICollectionReusableView

//To configure the appearance of your cell, add the views needed to present the data item’s content as subviews to the view in the contentView property. Do not directly add subviews to the cell itself.
@property (nonatomic, readonly) UIView *contentView; // add custom subviews to the cell's contentView,容器

// Cells become highlighted when the user touches them.
// The selected state is toggled when the user lifts up from a highlighted cell.
// Override these methods to provide custom UI for a selected or highlighted state.
// The collection view may call the setters inside an animation block.
@property (nonatomic, getter=isSelected) BOOL selected; //是否选择
@property (nonatomic, getter=isHighlighted) BOOL highlighted; //是否高亮

// Override this method to modify the visual appearance for a particular
// dragState.
//
// Call super if you want to add to the existing default implementation.
//
//
- (void)dragStateDidChange:(UICollectionViewCellDragState)dragState API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);

// The background view is a subview behind all other views.
// If selectedBackgroundView is different than backgroundView, it will be placed above the background view and animated in on selection.
@property (nonatomic, strong, nullable) UIView *backgroundView;//背景View,相当于unselected状态
@property (nonatomic, strong, nullable) UIView *selectedBackgroundView;//选中后的背景View，将往上移，移到backgroundView的上面

@end

NS_ASSUME_NONNULL_END
