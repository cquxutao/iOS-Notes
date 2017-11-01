//
//  TTView.swift
//  MemoryGraphDemo
//
//  Created by tennyxu on 20/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

import UIKit

typealias Action = () -> Void

class TTView: UIView {

    /*
    // Only override draw() if you perform custom drawing.
    // An empty implementation adversely affects performance during animation.
    override func draw(_ rect: CGRect) {
        // Drawing code
    }
    */
  
  var action: Action?
  
  init(action: @escaping Action) {
    self.action = action;
    super.init(frame:CGRect.zero)
  }
  required init?(coder aDecoder: NSCoder) {
    fatalError("init(coder:) has not been implemented")
  }

}
