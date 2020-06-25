# oresat-structure

[Join the chat at https://pdxaerospace.slack.com/messages/CG1QEGQDN](https://pdxaerospace.slack.com/messages/CG1QEGQDN)  
Mechanical structure for [OreSat](http://www.oresat.org)

This repo contains the top-level assembly of OreSat and the trivial subassemblies. If you'd like to contribute, join us on Zoom ([Fridays at 2 PM](https://pdx.zoom.us/j/173663228) and [Sundays at 10 AM](https://pdx.zoom.us/j/97369603680), Pacific Time), [read the issues][issues], and/or read the [contributions guide.][contrib]

# Please read our notes on [using Git Bash for Structure](https://github.com/oresat/oresat-structure/blob/master/GitBashNotes.md) before you start!


## Tips 
### How to Select all COTS parts
* Tools -> Component Selection -> Advanced Select...
* Either:
  * Filter for document names which contain `COTS`. Name this selection and save it.
  * Import `selectCOTS.xml`
* Apply the selection.
* Edit -> Hide -> Current Display State  
This hides any components which come from the `COTS/` directory (really anything with "COTS" in the name), which reduces lag significantly.  
If you want to show them again, use the same filter process, but show the current display state. 
If you want to show everything, you can just ctrl+a in the feature tree. If you're showing lots of COTS parts, please hide them before committing, since it can cause the model to load very slowly.

### How to Use the OreSat Materials Database
- Tools -> Options -> File Locations 
- Show folders for Material Databases.
- Add the OreSat repo to the list.

You can easily extend and modify the database through the "Edit Material" menu. It's a plain XML file, so Git will track it as usual.
Do _not_ simply copy the database to the default folders! Other people won't be able to access the materials you add/change.

## TODO:  
If you're looking for tasks to complete, check the [issues] or the [meeting notes]. This README is just too low-traffic to be useful as a TODO.

## Repo Structure
- OreSat.SLDASM  
_The complete assembly of OreSat_
- AssemblyJig
_What we use to hold OreSat on tables/for display_
- Backplane  
_The hub which provides power and data to all the boards_
- BatteryCard 
_The assembly that holds the batteries to the card; includes inhibit switches_
- Cameras
_Parts/subassemblies for the cameras_
- COTS  
_Any Commercial-Off-The-Shelf parts -- screws, connectors, et cetera._
- DebugConnector  
_The connector that allows for easy debugging of the satellite_
- Endcap  
_The boards that are placed on the +Z and -Z ends of the satellite_
- Endcards  
_The cards placed next to the Endcaps; hold the deployable antennas_
- Frames
_The +X and -X Frames, as well as the Y frames; wedges and triangles_
- GenericCard  
_Parts/subassemblies for the generic card; other cards for OreSat_
- LICENSE 
_CERN OHL licensing_
- ReactionWheels
_The wheels that are located in the center of OreSat and help it spin while in orbit_
- Solar  
_Solar panel boards
- VibrationJig  
_The fixtures that hold OreSat on the vibration table during testing_
- VolumeKeepout  
_Solids for quickly checking if we conform to the CDS, by checking for interferences_


## Terminology
These are just some terms that are relevant to the structure, non-obvious to an MME, or non-standard.  
- The X and Z axes are aligned to the features described below, and the Y axis is oriented to obey the right hand rule. The axes of the top-level assembly follow this convention. This convention matches that of our launch provider.
- A _board_ is any printed circuit board (PCB).
- A _card_ a board that slides into the rack structure of the satellite.
- An _endcap_ is a board that is screwed onto one of the +/-Z faces.
- An _endcard_ is a card that slides in under the +Z EndCap or above the -Z EndCap.
- _Rack_ and _structure_ both refer to the assembly of aluminum _frames_ to which all the boards mount.
- The _sides_ are the +/-Y components of the rack. They have the slots that the cards slide into.
- The _-X side_ is the location of the backplane, while the _+X side_ is placed on last, acting somewhat like a lid
- The _backplane_ is the long board that sits on the -X face of the satellite. It transfers power, data, and RF between the boards.
- The _turnstile_ antenna is the four-pronged antenna on the -Z face of the satellite. It provides an omnidirectional, low-data-rate signal to the ground.
- The _helical_ or _high gain_ antenna is the spiral, single-pronged antenna on the +Z face of the satellite. It's the narrow-beam, high-data-rate antenna the satellite uses for transmitting video.


## License 
Copyright Portland State Aerospace Society 2018.

This documentation describes Open Hardware and is licensed under the CERN OHL v. 1.2.
You may redistribute and modify this documentation under the terms of the CERN OHL v.1.2. [http://ohwr.org/cernohl](http://ohwr.org/cernohl).
This documentation is distributed WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING OF MERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A PARTICULAR PURPOSE. 
Please see the CERN OHL v.1.2 for applicable conditions.

[reaction wheels]: https://github.com/oresat/reaction-wheels
[issues]: https://github.com/oresat/oresat-structure/issues
[contrib]: https://github.com/oresat/oresat-structure/blob/master/.github/CONTRIBUTING.md
[meeting notes]: https://docs.google.com/document/d/1SXFwl-Lf-ymAFzhNi_DNS9qGwW9vnjGsETkxD0hkKp0/edit?usp=sharing
[]: 
[]: 
