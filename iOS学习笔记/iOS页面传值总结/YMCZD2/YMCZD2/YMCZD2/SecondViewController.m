//
//  SecondViewController.m
//  YMCZD2
//
//  Created by tennyxu on 06/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "SecondViewController.h"

@interface SecondViewController (){
    int p_number;
}

@end

@implementation SecondViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    p_number = 0;
    self.delegate = [self.tabBarController.viewControllers objectAtIndex:0];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (IBAction)btn:(id)sender {
    ++p_number;
    if ([self.delegate respondsToSelector:@selector(incrementBy1:)]) {
        [self.delegate incrementBy1:p_number];
    }
    
}
@end
