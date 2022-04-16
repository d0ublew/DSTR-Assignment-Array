[33mcommit e4fd25b566adc39776897cfc4e516f60cef27c89[m[33m ([m[1;36mHEAD -> [m[1;32mmain[m[33m)[m
Merge: bb66548 a0478ae
Author: juz410 <kokfeengtan@gmail.com>
Date:   Sat Apr 16 16:10:10 2022 +0800

    Merge branch 'main' of https://github.com/d0UBleW/DSTR-Assignment-Array

[33mcommit bb66548dece265c5eabedb21771833ae48db1e4e[m[33m ([m[1;31morigin/kokfeengdisplay[m[33m, [m[1;32mkokfeengdisplay[m[33m)[m
Author: juz410 <kokfeengtan@gmail.com>
Date:   Sat Apr 16 16:02:01 2022 +0800

    Add Student display tutor into displayTutor() method

[33mcommit a0478ae82439255229bda75f8a999dfbaa7642f4[m[33m ([m[1;31morigin/main[m[33m, [m[1;31morigin/HEAD[m[33m)[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Sat Apr 16 14:38:24 2022 +0800

    remove test.txt

[33mcommit 42ef01e0a1961fabd799d03c854a26114b917b0f[m
Author: juz410 <kokfeengtan@gmail.com>
Date:   Sat Apr 16 14:24:39 2022 +0800

    Added authentication.cpp,modified display.cpp,created menu template in admin_menu.cpp and student_menu.cpp

[33mcommit dce29f45b9120845c96d564928f3855f4901de71[m
Author: juz410 <kokfeengtan@gmail.com>
Date:   Sat Apr 16 12:26:41 2022 +0800

    implemeting display function and create menu.cpp

[33mcommit e5c1833c2225f89c1f4514673f65f3ba9ffe6d73[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Sat Apr 16 10:00:28 2022 +0800

    feat(file2struct): create function to store tutor

[33mcommit 2be0209348f12ab53527d36f9e321aa0bb3642f1[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Sat Apr 16 09:27:04 2022 +0800

    refactor(*): global variable
    
    Set text file path to global variable, move global variable to header
    file

[33mcommit a7cd564aa663ec215ab6e5c8e4de7791753d2657[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Sat Apr 16 09:06:22 2022 +0800

    refactor(file2struct): code preference
    
    Change function design from `pass by reference` to `return by value`
    which rely on `RVO` for performance optimization, but will have slower
    performance when dealing with large object.
    
    Further reading: [Copy elision](https://en.wikipedia.org/wiki/Copy_elision)

[33mcommit 87743896601971bdd06d382c413ae32ee0bf5c2e[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Fri Apr 15 22:15:48 2022 +0800

    feat(*): remove unused file

[33mcommit 5f1a477a8012570ab432b82e7bbdda3f38d364dd[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Fri Apr 15 22:14:51 2022 +0800

    fix(sln): project scoping

[33mcommit 7ae5aa28139a1cf6ce8f79e0feb0e67a1fa66b41[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Fri Apr 15 22:13:02 2022 +0800

    feat(*): remove unused file

[33mcommit 2a3f23d5fc04cea7eea5bbf31a6718c391b022c3[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Fri Apr 15 22:11:44 2022 +0800

    Squashed commit of the following:
    
    commit 69b771f9109447122209386402aabac0439b2633
    Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
    Date:   Fri Apr 15 22:09:43 2022 +0800
    
        feat(*): vector implementation
    
    commit 88345120e0fa7e22c772fb2f82b8ea3b6babf981
    Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
    Date:   Fri Apr 15 21:00:42 2022 +0800
    
        test vector
    
    commit a0bbf0fcbdb826d9c126ddad4a23a0fabc3474f2
    Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
    Date:   Fri Apr 15 16:03:41 2022 +0800
    
        refactor(*): change to vector implementation
    
    commit d563a5916b07028536a449f4b718c869dd7f2049
    Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
    Date:   Fri Apr 15 15:47:27 2022 +0800
    
        Test

[33mcommit 008580fbc254ac08f47c51f0b4ae41e9cb33b6f1[m
Author: juz410 <kokfeengtan@gmail.com>
Date:   Fri Apr 15 10:14:56 2022 +0800

    Testing Display

[33mcommit 4620aaa6a6ad5dbeec01e0a49cda564ba6421dea[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Thu Apr 14 22:06:23 2022 +0800

    feat(sln): add filter name Data
    
    Text file now can be grouped under Data filter

[33mcommit b6a0e3c970b40536cfbaa7612951744e274f8e3b[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Thu Apr 14 22:00:41 2022 +0800

    fix(main): file path

[33mcommit 1e314a5b488a03e13f401a218a9cbe759f47064c[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Thu Apr 14 21:59:10 2022 +0800

    feat(data): group text file under `data` directory

[33mcommit 9959f7cadc40383a53feb5ee280ed8b59ee9ceff[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Thu Apr 14 21:58:44 2022 +0800

    feat(sln): project scoping

[33mcommit d381e1fd65a6b1e2415bf8b94934139a0cc61588[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Thu Apr 14 21:51:20 2022 +0800

    feat(*): functions to import text file

[33mcommit 47fc90545fc11f62fa37d263dc92a27c6bb86669[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Thu Apr 14 21:07:08 2022 +0800

    feat(tutor): create struct for tutor array

[33mcommit bb700f237136eaf3ed12d209978d76918c9ede96[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Thu Apr 14 20:47:26 2022 +0800

    feat(sln): project scope

[33mcommit 6dcde93a2ee80d216e5c4ad582a94a67e7321fb4[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Thu Apr 14 20:43:13 2022 +0800

    feat(*): add tutor, date, subject, center struct

[33mcommit 84bdd825dfb10f24f79fd36701be148916188635[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Thu Apr 14 18:36:46 2022 +0800

    feat(main): Hello, World!

[33mcommit e07754183c2f845cb46d05a69bf0f4941a4ea81f[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Thu Apr 14 18:34:06 2022 +0800

    feat(*): create main file

[33mcommit a2a03542a01fb3847b015e328a6bf8ba1acd4246[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Thu Apr 14 18:31:42 2022 +0800

    feat(git): git config
    
    Append `.gitignore` with `C++` template

[33mcommit f9aa449fd564d6141d07e9318a480be141c3bfa6[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Thu Apr 14 18:29:04 2022 +0800

    Add project files.

[33mcommit 910d4adcd8a5e410fd2c38918de1fa932da92076[m
Author: d0UBleW <66501624+d0UBleW@users.noreply.github.com>
Date:   Thu Apr 14 18:29:02 2022 +0800

    Add .gitattributes, .gitignore, and README.md.
