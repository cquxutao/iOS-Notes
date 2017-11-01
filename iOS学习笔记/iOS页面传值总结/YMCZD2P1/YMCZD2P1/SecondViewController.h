//
//  SecondViewController.h
//  YMCZD2P1
//
//  Created by tennyxu on 19/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol SecondViewControllerDelegate <NSObject>

- (void)increment:(id)source withdata:(NSInteger)para;

@end

@interface SecondViewController : UIViewController

@property(nonatomic,weak) id<SecondViewControllerDelegate> delegate;

@end

