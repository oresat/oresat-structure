# Oresat Structure
If you want to help build a satellite, you're in the right place. This document serves as a style guide for SolidWorks parts, drawings, and assemblies.

## SolidWorks
We're currently using SolidWorks 2016-2017. We will be switching to the 2018 version in July. __Please avoid committing files created with versions later than 2016.__ Check `Help -> About SOLIDWORKS`, if you aren't sure what version you have.

Due to the proprietary nature of SolidWorks (SW) files, Git can't `diff` our CAD. 
To avoid massive conflicts, we therefore try to have lots of simple parts and subassemblies. This way, we can make changes only to the relevant parts or assemblies, without modifying anything we don't need to.

For example, Alice could make changes to the tail card assembly while Bob mankes changes to the reaction wheels assembly. 
Even though they are both a part of `OreSat.SLDASM`, those changes will not conflict\*, since they modify separate files.

### Dealing with SW "touching" files
\* SW likes to _touch_ (change the date-modified metadata) of its files when it rebuilds assemblies, even if nothing about the assembly has changed. 
So, for example, if Alice has `OreSat.SLDASM` open while editing the tail card assembly and she switches focus to the `OreSat.SLDASM` window, SW will rebuild the assembly. Then, Git would see `OreSat.SLDASM` as having changed. 
So, Alice may end up pushing "changes" to that file, even though none have been made. 
Generally, this isn't a big deal, but it can cause confusion and anxiety when people have to open up models from conflicting branches and try to find the differences. (Especially when there are no differences!)

Thus, __it is strongly preferred that you pay attention to what changes you are making and only commit real changes.__
This is easier to do when you break up your work/commits into deliberate chunks. (i.e., _don't_ hop between unrelated tasks and put those changes in the same commit.)
It also helps to run `git reset --hard` or `git stash` after a commit, in order to reset any superfluous changes to super-assemblies like `OreSat.SLDASM`

This same shenanigan also applies to parts, to some extent. SolidWorks will try to update files from older versions of SolidWorks. 
This usually only happens when importing COTS models, and isn't much of a problem for us. Ideally, COTS files should never be changed after they are first committed. 

### Dealing with references
References in SW can be really volatile in large/complicated assemblies. You can identify if a part/assembly contains a reference by a little "->" appending the name of a feature in the feature tree. (It may have another character after it, depending on whether the referenced file is open or if SW was able to find it. "->?" is common.)

__References should be avoided if at all possible.__ It's easy to break a part/assembly with lots of references.
There are two ways I (Joe) like to handle this. First, you can use the evaluate->measure tool to directly measure the necessary dimension. 
Second, you can create referencing sketches, over-define those sketches with dimensions, then remove the reference constraints on those sketch entities. 
(If that doesn't make sense, bug @Joedang about it. If it doesn't make sense to a lot of people, someone should make a little guide with screenshots.)

### Dealing with derived parts
Sometimes, you want to base a new part off of an existing part. The obvious way to do this is to open the older part, save it with a new name, and start making your changes. 
This has one major downside, though: changes to the older part will not be reflected in the newer part. 

It's preferred that you use an assembly to make your changes to the old part. 
For example, say you want to make a board similar to `Generic/Generic_board.SLDPRT` but with a hole for a camera to look through. You would make a new assembly named `Camera/peekaboo.SLDASM` (just an example), put `Generic/Generic_board.SLDPRT` in the assembly, and then make an extrude cut in the shape of the hole you want. 

By using an assembly for your derived part, any changes to `Generic/Generic_board.SLDPRT` will get automatically propagated through to `Camera/peekaboo.SLDASM`.
Compare this to the copy-and-edit strategy where you would need to _manually_ transcribe those changes from `Generic/Generic_board.SLDPRT` to `Camera/peekaboo.SLDPRT`. 
Hopefully it's obvious that such a strategy would be very error-prone and just not viable if you've got many parts all derived from one part. (And, we definitely will be deriving a lot of boards from `Generic/Generic_board.SLDPRT`)

#### Note:
You would _not_ use the "edit part" feature to edit `Generic/Generic_board.SLDPRT`, since that would change the original part. 
You would add that feature _to the assembly itself._
Also, when you go to make technical drawings or do CAM, you would need to use `Camera/peekaboo.SLDASM`, _not_ the generic board. 

### Sketches
It's strongly preferred that all sketches be fully defined. Otherwise, unexpected changes may occur after those sketches have been forgotten about. 
To that same end, if a sketch references another part, that reference should be converted to a hard dimension when you're done prototyping the sketch. 
External references can easily cause unexpected changes and break assemblies, especially in large assemblies like OreSat. 

### Feature Tree Hygene
It's strongly preferred that features be given descriptive names. (i.e., if you have something called `Cut-Extrude10`, you're doing it wrong.) 
However, this does not apply to features made via the Hole Wizard. If you don't manually name them, Hole Wizard features automatically update their name.
These automatic names are very useful to have if someone needs to, for example, change all M2 screws to M3. 

Additionally compound features should be grouped into descriptively named folders. For example, if you create screw mounts by extruding a face, filleting the edges, adding a threaded hole, and creating an array from that, then those should be grouped together in a folder named `screw_mounts`.

### Naming Conventions
It's preferred that file and directory names not contain spaces. This makes handling files with shell scripts easier.

Subsystems should always be in their own directory. The only SW file in the root of the repo should be the top-level OreSat assembly. Subsystem directories should start with a capital letter. The top level assembly (or part) within the subsystem's directory should have the exact same name as the directory.

Manual version numbers should not appear in the repo. (For example, there shouldn't be any files named `widgetv0.3`, `widgetv0.3`, et cetera.) If you need to experiment with something, use branches (`git branch dev_alice`, `git checkout dev_alice`, make some commits. If you want to incorporate those changes: `git checkout master`, `git merge dev_alice`).
If you want to keep track of major changes in the structure, use tags. `git tag v6.9` to add the tag "v6.9" to the current commit. `git checkout v0.5` to checkout the commit with tag "v0.5". `git push --tags` to push your tags to GitHub. `git tag -l` to see the available tags.

## Drawings
Check out these drawings to get an idea of the preferred style:  
- [generic board](/Generic/Generic_board.pdf)
- [backplane board](/Backplane/Backplane_board.PDF)
- [solar board](/Solar/Solar_board_drawing.PDF)

When placing things in EAGLE, the electrical engineers must enter Cartesian coordinates with the origin in the lower left corner. So, it's required that any drawings of PCBs have a page with "ordinate dimensions". 

Additionally, any boards with less than about 3 mm of clearance have annotations indicating this, so the ECEs know if they can put components there.

It's strongly preferred that drawings of boards also include the usual feature-oriented dimensions that are common to technical drawings. 

For complicated parts, it's preferred to have the first page only show overall dimensions and the locations of all detail views. The internal features should be shown on the following pages via the detailed views.

## Version numbers
### tags
Rather than polluting the repo with directories and files named `v0.5/`, `helical_v1.6.SLDPRT`, and so-on, we use tags. There's plenty of documentation online and in the man pages on this (see `man git tag` or `git tag -h`). 
The versions mostly designate non-backwards-compatible changes to the structure of the satellite. 
So, changing the positioning of the connectors, the slots, the screws, et cetera would be a good justification for a new version number. 
Changing the order of the cards withing the rack would not be a good justification for a new version number. 

### engraved labels
In order to identify the versions of our printed/machined prototypes, the aluminum parts of the structure (sides, front, back) are engraved with their version number and the date associated with that version. These can be changed by modifying the `VERSION_LABEL` feature in the respective parts.
