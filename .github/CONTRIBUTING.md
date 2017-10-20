# Oresat Structure

## SolidWorks
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

## Version numbers
### tags
Rather than polluting the repo with directories and files named `v0.5/`, `helical_v1.6.SLDPRT`, and so-on, we use tags. There's plenty of documentation online and in the man pages on this (see `man git tag` or `git tag -h`). 
The versions mostly designate non-backwards-compatible changes to the structure of the satellite. 
So, changing the positioning of the connectors, the slots, the screws, et cetera would be a good justification for a new version number. 
Changing the order of the cards withing the rack would not be a good justification for a new version number. 

### engraved labels
In order to identify the versions of our printed/machined prototypes, the aluminum parts of the structure (sides, front, back) are engraved with their version number and the date associated with that version. These can be changed by modifying the `VERSION_LABEL` feature in the respective parts.
