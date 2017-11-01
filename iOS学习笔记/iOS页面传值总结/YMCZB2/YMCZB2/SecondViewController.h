//
//  SecondViewController.h
//  YMCZB2
//
//  Created by tennyxu on 05/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^incrementBy1) (int number);

@interface SecondViewController : UIViewController

- (IBAction)btn:(id)sender;

@property(nonatomic,strong) incrementBy1 block;

@end

