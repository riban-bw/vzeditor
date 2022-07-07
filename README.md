VZEditor
=========

Editor for Casio VZ-1 / VZ-10M synthesizer (and possibly VZ-8).

This application allows transfer of voice patch data between Casio VZ-x synthesizers and a personal computer. The voice patch may be edited on the personal computer using a graphical interface. Patches may be saved to and restored from disc.

Envelopes are edited by click and drag of nodes on the envelope curve. To add a node, double click where the new node should be. All nodes after this point are moved to the right. To remove a node, double click on it. All nodes after this point are removed. **This functionality is not yet implemented**

There is a voice library manager allowing assignment of a description and group to each voice and file storage of voices.

The application is developed using cross-platform libraries so should work with GNU/Linux, Microsoft Windows and Apple OS X. It is developed on Ubuntu and mingw and is tested on those platforms.

This application depends on wxWidgets (tested with V3.1) and wxMidi which in turn depends on portmidi (source files included). I use the open source Code::Blocks IDE (project files are stored in version control).

This is open source software, released under the GPL V3. Copyright riban (Brian Walton) 2014-2020.

# Building

The repository has dependency on other repositories so you will need to checkout submodules. This can be done when cloning the git repository:

```
git clone --recurse-submodules https://github.com/riban-bw/vzeditor.git
```

Or after cloning by running the following command from within the local vzeditor git repository.

```
git submodule update --init
```

The Code::Blocks project should build on Windows with some small tweaks, e.g.

- Set location of wxWidgets in global variable 'wx'
- Set compiler to MinGW (current project uses MinGW 64)

Linux and MacOS should build with the Makefile:

```
make clean
make vzeditor
```

I should probably tweak Makefile to support all platforms...

# Usage

VZEditor starts and shows its graphical user interface:

![Voice Library](https://user-images.githubusercontent.com/3158323/73539372-2a288a00-4425-11ea-97d3-b3ff625a0ae6.png)

The MIDI input and output port may be selected from the drop-down lists in the header.

The Casio VZ synthesizer must be configured to send and receive System Exclusive MIDI messages, e.g enable menu 3-04 on VZ-1.

When VZ sysex data is received and correctly parsed, the "Get Voice" or "Get Operation" buttons enable. Pressing one of these will take the received voice / operational data and populate the appropriate editor page. The "New Library" button creates a new library and saves the currently loaded voice and operational data.

The "Send" button sends the voice or operational data currently being edited. If the "Auto Update" box is ticked then this is sent after each parameter change.

There are three tabs within the editor:
- Voice Library
- Voice Editor
- Operation Editor

# Voice Library

The Voice Library lists each voice within the currently loaded library.

![image](https://user-images.githubusercontent.com/3158323/73608145-05fcb280-45b7-11ea-8f62-e53b91017aa7.png)

A library may be loaded by using the File->Open menu option. Each voice has a name, description, group and type. Currently these parameters may not be edited but will be in a future release.

Double clicking on voice will open the Voice Editor and load the voice data.

# Voice Editor

The Voice Editor allows modification of each parameter of a VZ voice.

![Voice Editor](https://user-images.githubusercontent.com/3158323/73540594-3b26ca80-4428-11ea-9490-7d8cd38e6872.png)

If "Auto Update" is enabled then changes are sent to the MIDI output immediately otherwise the "Send" button must be pressed to hear changes on the synth.

Sending a voice from the VZ synth will populate a receive buffer in the VZEditor and enable the "Get Voice" button. Pressing this button will load the received voice into the editor, so the workflow to edit a voice that exists within the synthesizer is:

- Connect VZ synth to PC MIDI input
- Select the corresponding MIDI input from VZEditor "MIDI Input Port" drop-down
- Enable SysEx within VZ synth
- Press preset button on VZ synth
- Press "Get Voice" button within VZEditor
- Edit voice parameters
- Press "Send" button (or enable "Auto Update")
- Within VZ synth save buffer to preset 
 
# Operation Editor

Operation editor is not yet implemented but should work similar to voice editor, acting on operational data instead of voice data.

# On-screen Keyboard

There is a checkbox that allows an MIDI keyboard to be displayed.

![image](https://user-images.githubusercontent.com/3158323/73608111-9ab2e080-45b6-11ea-9ff2-b9349c51bf1a.png)

The keyboard acts as a monophonic MIDI controller. Left clicking on a key will send a note on MIDI event. Releasing the left mouse button will send a note off MIDI event. Click and hold whilst moving between keys will trigger a glissando. The further up the key the click, the quieter the note on (lower velocity.) MIDI channel may be selected and program change may be sent.

# Accessibility and keyboard short-cuts

VZEditor is designed to be accessible for a wide range of users with varying abilities. All elements should be controllable via keyboard short-cuts and pointer, e.g. mouse motion and click. Some mouse operations may require a right mouse button which may be emulated with Ctrl+left click on single button mouse. Each selectable control has a tool-tip which describes its use. Screen readers may be configured to read these tool-tips.

Keyboard short-cuts:

Key | Modifier | Action
--- | -------- | ------
 0 | ALT | Focus MIDI input selector in header
 1 | ALT | Show library editor and focus list
 2 | ALT | Show voice editor
 3 | ALT | Show operation editor
 K | ALT | Show keyboard and focus midi channel selector
 F | ALT | Show file menu
 V | ALT | Show view menu
 H | ALT | Show help menu
F4 | ALT | Close application
 O | CTRL | Open file
 S | CTRL | Save file
F1 | None | Show about dialog 

# Notes

Each voice and operation data is saved as an individual file. Library points to these files so deleting or moving files may break library. It may be advantageous to archive the library and sysex files in a single file (issue #29).

Library does not yet assign tones to MIDI programs (issue #28).

MIDI ports are not dynamically updated. Adding a port will not show in the list whilst VZEditor is running and removing a port may crash VZEditor (issue #2).

# Testing

Unit tests are currently under development. It is an aspiration to have automated testing and continuous integration of test results.

Manual test cases are [here](https://riban.app.testcollab.com/index.php/#/new/project/4).
