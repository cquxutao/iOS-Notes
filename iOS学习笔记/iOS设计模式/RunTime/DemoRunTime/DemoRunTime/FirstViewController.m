//
//  FirstViewController.m
//  DemoRunTime
//
//  Created by tennyxu on 04/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "FirstViewController.h"
#import <objc/runtime.h>
#import "Person.h"
#import "Person+PersonCategory.h"

@interface FirstViewController ()

- (IBAction)getAllVariable:(id)sender;
- (IBAction)getAllMethods:(id)sender;
- (IBAction)changeVariable:(id)sender;
- (IBAction)addProperty:(id)sender;
- (IBAction)addm:(id)sender;
- (IBAction)changeMethod:(id)sender;


@end

@implementation FirstViewController {
  Person *per;
}

- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view, typically from a nib.
  per = [[Person alloc] init];
}


- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}


- (IBAction)getAllVariable:(id)sender {
  unsigned int count = 0;
  Ivar *allVariables = class_copyIvarList([Person class], &count);
  for (unsigned int i = 0; i < count; ++i) {
    Ivar ivar = allVariables[i];
    const char *variableName = ivar_getName(ivar);
    const char *variableType = ivar_getTypeEncoding(ivar);
    NSLog(@"name=%s,type=%s",variableName,variableType);
  }
}

- (IBAction)getAllMethods:(id)sender {
  unsigned int count = 0;
  Method *allMethods = class_copyMethodList([Person class], &count);
  for (unsigned int i =0; i < count ; ++i) {
    Method method = allMethods[i];
    SEL sel = method_getName(method);
    const char *methodName = sel_getName(sel);
    NSLog(@"method=%s",methodName);
  }
}

- (IBAction)changeVariable:(id)sender {
  NSLog(@"%@",per);
  unsigned int count = 0;
  Ivar *all = class_copyIvarList([Person class], &count);
  Ivar name = all[0];
  object_setIvar(per, name, @"xu");
  NSLog(@"%@",per);
  
}

- (IBAction)addProperty:(id)sender {
  per.height = 12.0;
  NSLog(@"%f",per.height);
}

- (IBAction)addm:(id)sender {
  //@selector(NewMethod),是该类添加的方法，在这个类中对应过来的名称
//  class_addMethod(<#__unsafe_unretained Class cls#>, <#SEL name#>, <#IMP imp#>, <#const char *types#>)
  class_addMethod([per class], @selector(NewMethod), (IMP)addmethod1, 0);
  [self NewMethod];
}


int addmethod1(id self, SEL _cmd){
  NSLog(@"add func1");
  return 1;
}

- (void) NewMethod{
  [per performSelector:@selector(NewMethod)];
}

- (IBAction)changeMethod:(id)sender {
  //不断的点击，就会一直处于交换之中
  /*
   *2017-09-04 12:56:25.460 DemoRunTime[15688:1672429] execute func2
   2017-09-04 12:56:25.831 DemoRunTime[15688:1672429] execute func1
   2017-09-04 12:56:26.394 DemoRunTime[15688:1672429] execute func2
   */
  Method m1 = class_getInstanceMethod([Person class], @selector(func1));
  
  Method m2 = class_getInstanceMethod([Person class], @selector(func2));
  
  method_exchangeImplementations(m1, m2);
  [per func1];
}

@end
