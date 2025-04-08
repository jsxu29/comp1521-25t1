
## Stat

Stat contains information about your file (or metadata). 

The relevant components of stat are here:
```
struct stat {
    ino_t st_ino;         /* inode number - index into the filesystem's table of file metadata structures */
    mode_t st_mode;       /* file type and permissions */
    uid_t st_uid;         /* user ID of owner */
    gid_t st_gid;         /* group ID of owner */
    off_t st_size;        /* total size, in bytes */
    blksize_t st_blksize; /* blocksize for filesystem I/O */
    blkcnt_t st_blocks;   /* number of blocks allocated */
    time_t st_atime;      /* time of last access */
    time_t st_mtime;      /* time of last modification */
    time_t st_ctime;      /* time of last status change */
};
```

ls -l ouput shows:
file permissions, the number of links, owner name, owner group, file size, time of last modification, and the file or directory name

Here is the full list of components of stat:

```
struct stat {
    dev_t     st_dev;     /* ID of device containing file */
    ino_t     st_ino;     /* inode number */ 
    mode_t    st_mode;    /* protection */
    nlink_t   st_nlink;   /* number of hard links */ 
    uid_t     st_uid;     /* user ID of owner */ 
    gid_t     st_gid;     /* group ID of owner */
    dev_t     st_rdev;    /* device ID (if special file, that this inode represents) */
    off_t     st_size;    /* total size, in bytes */
    blksize_t st_blksize; /* blocksize for file system I/O */
    blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
    time_t    st_atime;   /* time of last access */
    time_t    st_mtime;   /* time of last modification */
    time_t    st_ctime;   /* time of last status change */
};
```

### How to use it?

The stat function takes in a file name and the struct stat variable you want to store the metadata in; it returns 0 upon success, and -1 on error.

```
struct stat s;
if (stat(<file path name>, &s) != 0) {
    ...
}
```

### Modes

mode_t mode = s.mode;

```
is directory?   owner permissions    group permissions   other permissions
d               rwx                 rwx                 rwx
-               ---                 ---                 ---
```

Executing:
- executing a file: running the file
- executing a directory: can you enter it

Representation:
- mode is a 32 bit integer, and the last 9 bits of the mode represent permissions
- each permission has two possibilities (r or -, w or -, x or -)
- binary! each permission can be represented by a 0 or 1 bit
- each permission rwx group can be represented with an octal number

E.g.
```
                           rw-r--r--
mode_t mode = 0b .....     110100100
             &  S_IROTH =  000000100 -- 1 << 2 

                           000000100 >> 2 -> 000000001
                           000000000 >> 2 -> 000000000
```

- i.e. the other permissions read bit is represented by (mode & (1 << 2)) >> 2

- note: the way to represent whether it is a directory or not is different and you can find this out using the functions defined in the library below

### Useful stat constants

> S_ISREG(mode_t m) - returns is it a regular file? \
> S_ISDIR(mode_t m) - returns directory?

https://manpages.org/stat/2

> bit mask constants for permissions e.g. usually S_IWOTH = 0x02 = 0b000000010, example use: mode_t m & S_IWOTH != 0 to check if the other group has write permissions


### Chmod function

chmod - change mode
To get the manual page, it is under system calls section 2: `man 2 chmod`
