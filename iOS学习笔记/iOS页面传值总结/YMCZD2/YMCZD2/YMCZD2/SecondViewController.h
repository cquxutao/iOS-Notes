//
//  SecondViewController.h
//  YMCZD2
//
//  Created by tennyxu on 06/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol SecondViewControllerDelegate <NSObject>

-(void) incrementBy1:(int) number;

@end

@interface SecondViewController : UIViewController

- (IBAction)btn:(id)sender;

@property (nonatomic,weak) id delegate;

@end

