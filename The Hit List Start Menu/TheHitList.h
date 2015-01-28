/*
 * TheHitList.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class TheHitListItem, TheHitListApplication, TheHitListColor, TheHitListDocument, TheHitListWindow, TheHitListRichText, TheHitListCharacter, TheHitListParagraph, TheHitListWord, TheHitListAttributeRun, TheHitListAttachment, TheHitListTask, TheHitListGroup, TheHitListFolder, TheHitListList, TheHitListTag, TheHitListSmartFolder, TheHitListApplication;

enum TheHitListSaveOptions {
	TheHitListSaveOptionsYes = 'yes ' /* Save the file. */,
	TheHitListSaveOptionsNo = 'no  ' /* Do not save the file. */,
	TheHitListSaveOptionsAsk = 'ask ' /* Ask the user whether or not to save the file. */
};
typedef enum TheHitListSaveOptions TheHitListSaveOptions;

enum TheHitListPrintingErrorHandling {
	TheHitListPrintingErrorHandlingStandard = 'lwst' /* Standard PostScript error handling */,
	TheHitListPrintingErrorHandlingDetailed = 'lwdt' /* print a detailed report of PostScript errors */
};
typedef enum TheHitListPrintingErrorHandling TheHitListPrintingErrorHandling;



/*
 * Standard Suite
 */

// A scriptable object.
@interface TheHitListItem : SBObject

@property (copy) NSDictionary *properties;  // All of the object's properties.

- (void) closeSaving:(TheHitListSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) printWithProperties:(NSDictionary *)withProperties printDialog:(BOOL)printDialog;  // Print a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.

@end

// The application's top-level scripting object.
@interface TheHitListApplication : SBApplication

- (SBElementArray *) documents;
- (SBElementArray *) windows;

@property (copy, readonly) NSString *name;  // The name of the application.
@property (readonly) BOOL frontmost;  // Is this the frontmost (active) application?
@property (copy, readonly) NSString *version;  // The version of the application.

- (void) save;  // Save
- (void) print:(id)x withProperties:(NSDictionary *)withProperties printDialog:(BOOL)printDialog;  // Print a document.
- (void) quitSaving:(TheHitListSaveOptions)saving;  // Quit the application.
- (BOOL) exists:(id)x;  // Verify if an object exists.
- (void) stopTiming;  // Stop the timer
- (void) pauseresumeTiming;  // Pause or resume the timer

@end

// A color.
@interface TheHitListColor : SBObject

- (void) closeSaving:(TheHitListSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) printWithProperties:(NSDictionary *)withProperties printDialog:(BOOL)printDialog;  // Print a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.

@end

// A document.
@interface TheHitListDocument : SBObject

@property (copy, readonly) NSString *name;  // The document's name.
@property (readonly) BOOL modified;  // Has the document been modified since the last save?
@property (copy) NSString *path;  // The document's path.
@property (copy, readonly) NSURL *file;  // The document's location on disk.

- (void) closeSaving:(TheHitListSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) printWithProperties:(NSDictionary *)withProperties printDialog:(BOOL)printDialog;  // Print a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.

@end

// A window.
@interface TheHitListWindow : SBObject

@property (copy, readonly) NSString *name;  // The full title of the window.
- (NSInteger) id;  // The unique identifier of the window.
@property NSInteger index;  // The index of the window, ordered front to back.
@property NSRect bounds;  // The bounding rectangle of the window.
@property (readonly) BOOL closeable;  // Whether the window has a close box.
@property (readonly) BOOL minimizable;  // Whether the window can be minimized.
@property BOOL minimized;  // Whether the window is currently minimized.
@property (readonly) BOOL resizable;  // Whether the window can be resized.
@property BOOL visible;  // Whether the window is currently visible.
@property (readonly) BOOL zoomable;  // Whether the window can be zoomed.
@property BOOL zoomed;  // Whether the window is currently zoomed.
@property (copy, readonly) TheHitListDocument *document;  // The document whose contents are being displayed in the window.

- (void) closeSaving:(TheHitListSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) printWithProperties:(NSDictionary *)withProperties printDialog:(BOOL)printDialog;  // Print a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.

@end



/*
 * Text Suite
 */

// Rich (styled) text
@interface TheHitListRichText : SBObject

- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) attachments;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.

- (void) closeSaving:(TheHitListSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) printWithProperties:(NSDictionary *)withProperties printDialog:(BOOL)printDialog;  // Print a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.

@end

// This subdivides the text into characters.
@interface TheHitListCharacter : SBObject

- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) attachments;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.

- (void) closeSaving:(TheHitListSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) printWithProperties:(NSDictionary *)withProperties printDialog:(BOOL)printDialog;  // Print a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.

@end

// This subdivides the text into paragraphs.
@interface TheHitListParagraph : SBObject

- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) attachments;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.

- (void) closeSaving:(TheHitListSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) printWithProperties:(NSDictionary *)withProperties printDialog:(BOOL)printDialog;  // Print a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.

@end

// This subdivides the text into words.
@interface TheHitListWord : SBObject

- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) attachments;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.

- (void) closeSaving:(TheHitListSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) printWithProperties:(NSDictionary *)withProperties printDialog:(BOOL)printDialog;  // Print a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.

@end

// This subdivides the text into chunks that all have the same attributes.
@interface TheHitListAttributeRun : SBObject

- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) attachments;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.

- (void) closeSaving:(TheHitListSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) printWithProperties:(NSDictionary *)withProperties printDialog:(BOOL)printDialog;  // Print a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.

@end

// Represents an inline text attachment. This class is used mainly for make commands.
@interface TheHitListAttachment : TheHitListRichText

@property (copy) NSString *fileName;  // The path to the file for the attachment


@end



/*
 * The Hit List Suite
 */

// A task
@interface TheHitListTask : TheHitListItem

- (SBElementArray *) tasks;

- (NSString *) id;  // Unique ID
@property (copy) NSString *title;  // The title of the task
@property (copy) TheHitListRichText *notes;  // The notes attached to the task
@property (copy) NSDate *startDate;  // Start date of the task
@property (copy) NSDate *dueDate;  // Due date of the task
@property double estimatedTime;  // Estimated time in seconds
@property (readonly) double actualTime;  // Actual in seconds
@property (copy, readonly) NSDate *canceledDate;  // The date the task was canceled on
@property (copy, readonly) NSDate *createdDate;  // The date the task was created on
@property (copy, readonly) NSDate *modifiedDate;  // The date the task was modified
@property NSInteger priority;  // The priority of the task
@property (readonly) BOOL archived;  // Whether the task is archived
@property BOOL canceled;  // Whether the task is canceled
@property BOOL completed;  // Whether the task is completed
@property (copy, readonly) NSString *url;  // The Hit List URL of the task 
@property (copy, readonly) NSDate *completedDate;  // The date the task was completed on
@property (readonly) BOOL repeating;  // Whether the task is repeating

- (void) beginTiming;  // Begin timing this task

@end

// An abstract superclass of list, folder, smart folder, and tag
@interface TheHitListGroup : TheHitListItem

- (NSString *) id;  // Unique ID
@property (copy) NSString *name;  // The title of the group
@property (copy, readonly) NSDate *modifiedDate;  // The date the list was modified on
@property (copy, readonly) NSDate *createdDate;  // The date the list was created on
@property (readonly) BOOL archived;  // Group is archived


@end

// A folder
@interface TheHitListFolder : TheHitListGroup

- (SBElementArray *) groups;


@end

// A list
@interface TheHitListList : TheHitListGroup

- (SBElementArray *) tasks;


@end

// A tag
@interface TheHitListTag : TheHitListGroup

- (SBElementArray *) tasks;


@end

// A smart folder
@interface TheHitListSmartFolder : TheHitListGroup

- (SBElementArray *) tasks;


@end

// The Hit List's top level scripting object.
@interface TheHitListApplication (TheHitListSuite)

@property (copy, readonly) TheHitListList *inbox;  // The Inbox
@property (copy, readonly) TheHitListList *todayList;  // The Today list
@property (copy, readonly) TheHitListList *upcomingList;  // The Upcoming list
@property (copy, readonly) TheHitListFolder *foldersGroup;  // Container group for folders
@property (copy, readonly) TheHitListFolder *tagsGroup;  // Container group for tags
@property (copy, readonly) TheHitListFolder *archiveGroup;  // Container group for archived lists and folders
@property (copy) NSArray *selection;  // List of tasks that the user has selected
@property (copy) TheHitListGroup *selectedGroup;  // Selected group
@property (copy, readonly) TheHitListTask *timingTask;  // The task currently being timed, if any

@end

