//
//  ViewController.m
//  DemoLeak
//
//  Created by tennyxu on 01/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "ViewController.h"
#import "People.h"

@interface ViewController ()

- (IBAction)buttonClick:(id)sender;

@end

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}


- (IBAction)buttonClick:(id)sender {
  People *people = [[People alloc] init];
  [people retain];
  people.str = @"hello leak";
  [people release];
}
@end
