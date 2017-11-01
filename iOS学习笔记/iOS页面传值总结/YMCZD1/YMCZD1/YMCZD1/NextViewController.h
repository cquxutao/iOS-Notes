//
//  NextViewController.h
//  YMCZD1
//
//  Created by tennyxu on 06/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol NextViewControllerDelegate <NSObject>

- (void) incrementBy1:(int) number;

@end

@interface NextViewController : UIViewController

@property(nonatomic,weak) id <NextViewControllerDelegate> delegate;

- (IBAction)btn:(id)sender;

@end
