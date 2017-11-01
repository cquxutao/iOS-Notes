//
//  ViewController.m
//  YMCZB1
//
//  Created by tennyxu on 05/08/2017.
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


// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
    NSLog(@"segue name: %@",segue.identifier);
    NextViewController *nVC = [segue destinationViewController];
    nVC.block = ^(int number) {
            _dis.text = [NSString stringWithFormat:@"%d",number];
        };
    
}


- (IBAction)btn:(id)sender {
    
//    UIStoryboard *mainStory = [UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]];
//    NextViewController *nVC = [mainStory instantiateViewControllerWithIdentifier:@"nextViewController"];
//    nVC.block = ^(int number) {
//        _dis.text = [NSString stringWithFormat:@"%d",number];
//    };
    
}
@end
