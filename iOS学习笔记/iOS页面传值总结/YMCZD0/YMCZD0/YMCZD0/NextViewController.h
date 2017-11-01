//
//  NextViewController.h
//  YMCZD0
//
//  Created by tennyxu on 06/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol NextViewControllerDeleggate <NSObject>

- (void) incrementBy1: (int) number;

@end

@interface NextViewController : UIViewController

@property (nonatomic,weak) id <NextViewControllerDeleggate> delegate;

@end
