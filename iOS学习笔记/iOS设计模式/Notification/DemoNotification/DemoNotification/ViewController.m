//
//  ViewController.m
//  DemoNotification
//
//  Created by tennyxu on 04/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
@property (strong, nonatomic) IBOutlet UITextView *dis;

@end

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view, typically from a nib.
  //
  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(dis:) name:@"TestX" object:nil];
  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(xx2) name:UIApplicationWillResignActiveNotification object:nil];
  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(xx3) name:UIApplicationDidBecomeActiveNotification object:nil];
}


- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
  [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)dealloc {
  [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)dis:(NSNotification *)not {
  NSDictionary *dic = [not userInfo];
  self.dis.text = [dic objectForKey:@"Y"];
  
}

- (void) xx2 {
  self.dis.backgroundColor = [UIColor redColor];
}

- (void) xx3 {
  self.dis.backgroundColor = [UIColor whiteColor];
}
@end
