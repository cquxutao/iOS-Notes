//
//  ViewController.h
//  YMCZD1
//
//  Created by tennyxu on 06/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NextViewController.h"

@interface ViewController : UIViewController <NextViewControllerDelegate>

- (IBAction)btn:(id)sender;
@property (weak, nonatomic) IBOutlet UILabel *dis;


@end

