//
//  FirstViewController.m
//  YMCZD2P1
//
//  Created by tennyxu on 19/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "FirstViewController.h"
#import "SecondViewController.h"

@interface FirstViewController () <SecondViewControllerDelegate>

@property (strong, nonatomic) IBOutlet UILabel *dis;

@end

@implementation FirstViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    _dis.text = @"0";
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark -- SecondViewControllerDelegate
- (void)increment:(id)source withdata:(NSInteger)para{
    //source暂时没用起来
    _dis.text = [NSString stringWithFormat:@"%ld",(long)para];
}
@end
