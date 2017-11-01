//
//  NextViewController.h
//  YMCZB1
//
//  Created by tennyxu on 05/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^incrementBy1) (int number);

@interface NextViewController : UIViewController
- (IBAction)btn:(id)sender;

@property (nonatomic,copy) incrementBy1 block;

@end
