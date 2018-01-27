# SW-stats
Farmore often data is either in ﬁles or is read in from some I/O channel (possibly a standard IP network, but in embedded systems typically from some custom source for that particular system). In this I will read data from a ﬁle and compute some statistics over that data. The ﬁle format is as follows:
studentID, grade
An example ﬁle would be:
22271102,87 
22271307, 93 
22271109, 77
22273009,62
92137,46
22273602,103
Some points to notice about this ﬁle:
1. It is in a comma-separated values (CSV) format, which is an extremely common format for storing data.
2. Each data record is kept on its own line.
