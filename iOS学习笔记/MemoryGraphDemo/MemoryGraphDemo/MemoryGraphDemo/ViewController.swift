//
//  ViewController.swift
//  MemoryGraphDemo
//
//  Created by tennyxu on 20/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

import UIKit


class ViewController: UIViewController {
  
  @IBOutlet weak var label:UILabel!
  var ttView:TTView?
  

  override func viewDidLoad() {
    super.viewDidLoad()
    // Do any additional setup after loading the view, typically from a nib.
    ttView = TTView(action:testf)
//    ttView = TTView(){ [unowned self] in
//      self.label.text = "hello tt";
//    }
  }
  
  func testf() {
    self.label.text = "hello tt"
  }

  override func didReceiveMemoryWarning() {
    super.didReceiveMemoryWarning()
    // Dispose of any resources that can be recreated.
  }
  

  


}

