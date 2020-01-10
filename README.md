vzeditor
=========

Editor for Casio VZ-1 / VZ-10M synthesizer (and possibly VZ-8).

This application allows transfer of voice patch data between Casio VZ-x synthesizers and a personal computer. The voice patch may be edited on the personal computer using a graphical interface. Patches may be saved to and restored from disc.

Envelopes are edited by click and drag of nodes on the envelope curve. To add a node, double click where the new node should be. All nodes after this point are moved to the right. To remove a node, double click on it. All nodes after this point are removed.

There is a voice library manager allowing assignment of a description and group to each voice and file storage of voices.

The application is developed using cross-platform libraries so should work with GNU/Linux, Microsoft Windows and Apple OS X. It is deleoped on Ubuntu and mingw and is tested on those platforms.

This application depends on wxWidgets (tested with V2.8 / V3.0) and wxMidi (source files included) which in turn depends on portmidi. (Portmidi libraries are not stored in github repository and must be sourced for your platform.) I use the open source Code::Blocks IDE (project files are stored in version control).

This is open source software, released under the GPL V3. Copyright riban (Brian Walton) 2014-2020.
