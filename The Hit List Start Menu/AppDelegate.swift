//
//  AppDelegate.swift
//  The Hit List Start Menu
//
//  Created by Du Song on 2015-01-26.
//  Copyright (c) 2015 Song Du. All rights reserved.
//

import Cocoa
import ScriptingBridge

@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate {

	@IBOutlet weak var statusMenu: NSMenu!

	var statusItem: NSStatusItem
	var cmd2Script = NSAppleScript(source: "tell application \"System Events\" to keystroke \"2\" using {command down}")!

	override init()	{
		let _NSSquareStatusItemLength: CGFloat = -2 // TODO: Workaround, should actually be: NSSquareStatusItemLength (see http://stackoverflow.com/questions/24024723/swift-using-nsstatusbar-statusitemwithlength-and-nsvariablestatusitemlength )
		self.statusItem = NSStatusBar.systemStatusBar().statusItemWithLength(_NSSquareStatusItemLength)
	}

	override func awakeFromNib() {
		self.statusItem.menu = self.statusMenu
		self.statusItem.highlightMode = true
	}


	func applicationDidFinishLaunching(aNotification: NSNotification) {
		self.statusItem.title = "✔"
	}

	func applicationWillTerminate(aNotification: NSNotification) {
		// Insert code here to tear down your application
	}

	func menuNeedsUpdate(menu: NSMenu!) {
		if (menu != self.statusMenu) {
			return
		}
		menu.removeAllItems()
		
		var thl:AnyObject = SBApplication.applicationWithBundleIdentifier("com.potionfactory.TheHitList")
		var list = thl.todayList!
		var timingURL = SBWorkaround.getUrl(thl.timingTask) as String?
		var tasks = list.tasks()
		for task in tasks {
			if task.completed! { continue }
			var item = NSMenuItem(title:SBWorkaround.getTitle(task), action: "statusMenuItemTask_Action:", keyEquivalent: "")
			item.representedObject = task.url!
			if (timingURL == task.url!) {
				item.state = NSOnState
			}
			menu.addItem(item)
		}
		
		menu.addItem(NSMenuItem.separatorItem())
		menu.addItem(NSMenuItem(title: "Quit The Hit List Start Menu", action: "statusMenuItemQuit_Action:", keyEquivalent: ""))
	}

	func statusMenuItemTask_Action(sender: NSMenuItem)	{
		var u = sender.representedObject as NSString
		var r = NSWorkspace.sharedWorkspace().openURL(NSURL(string:u)!)
		var thl:AnyObject = SBApplication.applicationWithBundleIdentifier("com.potionfactory.TheHitList")
		var list = thl.todayList!
		var tasks = list.tasks()
		for task in tasks {
			if u != task.url! {
				continue
			}
			task.beginTiming()
			_ = cmd2Script.executeAndReturnError(nil)
		}
	}
	
	func statusMenuItemQuit_Action(sender: NSMenuItem)	{
		NSApplication.sharedApplication().terminate(self)
	}
}

