//
//  NextViewController.h
//  YMCZD0P1
//
//  Created by tennyxu on 19/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol NextViewControllerDelegate <NSObject>

@optional
- (void)increment:(id)sender withPara:(NSInteger) para;

@end

@interface NextViewController : UIViewController

@property(nonatomic,weak) id<NextViewControllerDelegate> delegate;

@end
