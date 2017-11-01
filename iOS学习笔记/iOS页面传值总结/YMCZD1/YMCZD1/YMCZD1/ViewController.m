//
//  ViewController.m
//  YMCZD1
//
//  Created by tennyxu on 06/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "ViewController.h"
#import "NextViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    _dis.text = @"0";
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


-(void) prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender{
    NextViewController *nVC = [segue destinationViewController];
    nVC.delegate = self;
    
}

#pragma mark -- NextViewControllerDelegate



- (void)incrementBy1:(int)number {
    _dis.text = [NSString stringWithFormat:@"%d",number];
}

- (IBAction)btn:(id)sender {
}
@end
