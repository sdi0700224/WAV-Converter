# include <stdio.h>
# include <math.h>
# define _USE_MATH_DEFINES
# define MODE 1   /*MODE 1,2,3,4,5,6,7*/

void mysound(int, int, double, double, double, double);

int main(void)
{
    long sof, samplerate, bytesps, sizeofdata, count, i;
    int d1, d2, d3, d4, temp1, ch, format, wavef, stereo, blockal, bitsps, flag, cdistance, rubbish;
    if (MODE == 1)              /* Elegxos mode */
    {
        flag = 1;
        ch = getchar();
        if (ch != 'R')          /*Elegxos an yparxei to RIFF */
        {
            flag = 0;
        }
        ch = getchar();
        if (ch != 'I')
        {
            flag = 0;
        }
        ch = getchar();
        if (ch != 'F')
        {
            flag = 0;
        }
        ch = getchar();
        if (ch != 'F')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"RIFF\" not found\n");      /*Ektyposi lathous kai epistofi -1*/
           return(-1);
        }
        flag = 1;
        ch = getchar();         /*Olisthidi aristera kai prosthesi tou epomenou byte gia ti dimiourgia tis aksias toy arithmou*/
        sof = ch;
        ch = getchar();
        ch = ch << 8 ;
        sof = sof + ch ;
        ch = getchar();
        ch = ch << 16 ;
        sof = sof + ch;
        ch = getchar();
        ch = ch << 24;
        sof = sof + ch;
        fprintf (stderr, "size of file : %ld\n", sof);
        count = 0;          /*Enarksi metrisis xaraktirwn*/
        ch = getchar();
        count = count + 1;
        if (ch != 'W')      /*Sinexisi elegxwn nomimou arxeiou*/
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'A')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'V')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'E')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"WAVE\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        count = count + 1;
        if (ch != 'f')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'm')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 't')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != ' ')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"fmt\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();     /*me ton idio tropo sximatizoume tin aksia gia tous epomenous arithmous*/
        count = count + 1;
        format = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        format = format + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        format = format + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        format = format + ch;
        fprintf(stderr, "size of format chucnck: %d\n", format);
        if (format != 16)
        {
            fprintf (stderr, "Error! size of format chunck should be 16\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        wavef = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        wavef = wavef + ch ;
        fprintf(stderr, "WAVE type format: %d\n", wavef);
        if (wavef != 1)
        {
            fprintf (stderr, "Error! WAVE type format should be 1\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        stereo = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        stereo = stereo + ch ;
        fprintf(stderr, "mono/stereo: %d\n", stereo);
        if ((stereo != 1) && (stereo != 2))
        {
            fprintf (stderr, "Error! mono/stereo should be 1 or 2\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        samplerate = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        samplerate = samplerate + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        samplerate = samplerate + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        samplerate = samplerate + ch;
        fprintf(stderr, "samplerate: %ld\n", samplerate);
        ch = getchar();
        count = count + 1;
        bytesps = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        bytesps = bytesps + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        bytesps = bytesps + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        bytesps = bytesps + ch;
        fprintf(stderr, "bytes/sec: %ld\n", bytesps);
        ch = getchar();
        count = count + 1;
        blockal = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        blockal = blockal + ch ;
        fprintf(stderr, "block alignment: %d\n", blockal);
        if (bytesps != (samplerate * blockal)) /*Elegxos an ikanopoiei tin epiprostheti sinthiki*/
        {
            fprintf (stderr, "Error! bytes/second should be sample rate x block alignment\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        bitsps = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        bitsps = bitsps + ch ;
        fprintf(stderr, "bits/sample: %d\n", bitsps);
        if ((bitsps != 8) && (bitsps != 16))    /*Elegxos an einai mesa stis dyo times poy theloume*/
        {
            fprintf (stderr, "Error! bits/sampe should be 8 or 16\n");
            return(-1);
        }
        if (blockal != ((bitsps/8) * stereo)) /* elegxos an ikanopoiei tin sinthiki*/
        {
            fprintf (stderr, "Error! block allignment should be bits per sample / 8 x mono/stereo\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'd')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'a')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 't')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'a')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"data\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        count = count + 1;
        sizeofdata = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        sizeofdata = sizeofdata + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        sizeofdata = sizeofdata + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        sizeofdata = sizeofdata + ch;
        fprintf(stderr, "size of data chunk: %ld\n", sizeofdata);
        cdistance = count;  /*Vazoume se mia metavliti to ews twra metrima*/
        while (ch != EOF)   /*Diavasma epomenwn xaraktirwn*/
        {
            ch = getchar();
            if (ch != EOF)
            {
                count = count + 1; /*Sinexizoume na metrame tous xaraktires pou diavazontai*/
            }
        }
        if (sizeofdata > (count - cdistance)) /*Elegxos eparkwn dedomenwn meta ti dilwsi data*/
        {
            fprintf(stderr, "Error! insufficient data\n");
            return(-1);
        }
        if(sof != count) /*elegxos sinolikwn dedomenwn meta to size of file*/
        {
            fprintf(stderr, "Error! bad file size\n");
            return(-1);
        }
        return 0;
    }
    if (MODE == 2) /*Elegxos gia epomena MODE - Tha sxoliazontai mono ta diaforetika kommatia programmatos*/
    {
        flag = 1;
        ch = getchar();
        putchar(ch);
        if (ch != 'R')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        if (ch != 'I')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        if (ch != 'F')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        if (ch != 'F')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"RIFF\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        putchar(ch);    /*Ektypwsi xaraktirwn gia dimiourgia arxeiou wav*/
        sof = ch;
        ch = getchar();
        putchar(ch);
        ch = ch << 8 ;
        sof = sof + ch ;
        ch = getchar();
        putchar(ch);
        ch = ch << 16 ;
        sof = sof + ch;
        ch = getchar();
        putchar(ch);
        ch = ch << 24;
        sof = sof + ch;
        fprintf (stderr, "size of file : %ld\n", sof);
        count = 0;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 'W')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 'A')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 'V')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 'E')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"WAVE\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 'f')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 'm')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 't')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != ' ')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"fmt\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        format = ch;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 8 ;
        format = format + ch ;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 16 ;
        format = format + ch;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 24;
        format = format + ch;
        fprintf(stderr, "size of format chucnck: %d\n", format);
        if (format != 16)
        {
            fprintf (stderr, "Error! size of format chunck should be 16\n");
            return(-1);
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        wavef = ch;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 8 ;
        wavef = wavef + ch ;
        fprintf(stderr, "WAVE type format: %d\n", wavef);
        if (wavef != 1)
        {
            fprintf (stderr, "Error! WAVE type format should be 1\n");
            return(-1);
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        stereo = ch;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 8 ;
        stereo = stereo + ch ;
        fprintf(stderr, "mono/stereo: %d\n", stereo);
        if ((stereo != 1) && (stereo != 2))
        {
            fprintf (stderr, "Error! mono/stereo should be 1 or 2\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        samplerate = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        samplerate = samplerate + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        samplerate = samplerate + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        samplerate = samplerate + ch;
        fprintf(stderr, "samplerate: %ld\n", samplerate);
        temp1 = samplerate / 2;     /*Ypodiplasiasmos tou Sample Rate*/
        d4 = temp1 >> 24;           /*Olistisi deksia gia na paroume to kommati tou arithmou pou theloume na ektypwsoume kai apothikeusi toy se metavliti*/
        temp1 = temp1 - (d4 << 24); /*Metakinisi tou kommatiou aristera stin arxiki thesi pou eixe kai afairesi tou apo ton arxiko aritho gia na paroume meta ta epomena kommatia*/
        d3 = temp1 >> 16;           /*Sinexizoume mexri na teleiwsoun ta psifia toy arithmou me ton idio tropo*/
        temp1 = temp1 - (d3 << 16);
        d2 = temp1 >> 8;
        temp1 = temp1 - (d2 << 8);
        d1 = temp1;
        putchar(d1);
        putchar(d2);
        putchar(d3);
        putchar(d4);
        ch = getchar();
        count = count + 1;
        bytesps = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        bytesps = bytesps + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        bytesps = bytesps + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        bytesps = bytesps + ch;
        fprintf(stderr, "bytes/sec: %ld\n", bytesps);
        temp1 = bytesps / 2;    /*Akrivws to idio gia ta bytes per second gia na kratithei nomimo to arxeio kai na isxiei i eksiswsi me to block alliance*/
        d4 = temp1 >> 24;       /*Idia diadikasia me parapanw*/
        temp1 = temp1 - (d4 << 24);
        d3 = temp1 >> 16;
        temp1 = temp1 - (d3 << 16);
        d2 = temp1 >> 8;
        temp1 = temp1 - (d2 << 8);
        d1 = temp1;
        putchar(d1);
        putchar(d2);
        putchar(d3);
        putchar(d4);
        ch = getchar();
        putchar(ch);
        count = count + 1;
        blockal = ch;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 8 ;
        blockal = blockal + ch ;
        fprintf(stderr, "block alignment: %d\n", blockal);
        if (bytesps != (samplerate * blockal))
        {
            fprintf (stderr, "Error! bytes/second should be sample rate x block alignment\n");
            return(-1);
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        bitsps = ch;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 8 ;
        bitsps = bitsps + ch ;
        fprintf(stderr, "bits/sample: %d\n", bitsps);
        if ((bitsps != 8) && (bitsps != 16))
        {
            fprintf (stderr, "Error! bits/sampe should be 8 or 16\n");
            return(-1);
        }
        if (blockal != ((bitsps/8) * stereo))
        {
            fprintf (stderr, "Error! block allignment should be bits per sample / 8 x mono/stereo\n");
            return(-1);
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 'd')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 'a')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 't')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 'a')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"data\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        sizeofdata = ch;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 8 ;
        sizeofdata = sizeofdata + ch ;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 16 ;
        sizeofdata = sizeofdata + ch;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 24;
        sizeofdata = sizeofdata + ch;
        fprintf(stderr, "size of data chunk: %ld\n", sizeofdata);
        cdistance = count;
        while (ch != EOF)
        {
            ch = getchar();
            if (ch != EOF)
            {
                putchar(ch); /*Vazoume mesa stin epanalipsi kai tin entoli ektyposis*/
                count = count + 1;
            }
        }
        if (sizeofdata > (count - cdistance))
        {
            fprintf(stderr, "Error! insufficient data\n");
            return(-1);
        }
        if(sof != count)
        {
            fprintf(stderr, "Error! bad file size\n");
            return(-1);
        }
        return 0;
    }
    if (MODE == 3)
    {
        flag = 1;
        ch = getchar();
        putchar(ch);
        if (ch != 'R')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        if (ch != 'I')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        if (ch != 'F')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        if (ch != 'F')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"RIFF\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        putchar(ch);
        sof = ch;
        ch = getchar();
        putchar(ch);
        ch = ch << 8 ;
        sof = sof + ch ;
        ch = getchar();
        putchar(ch);
        ch = ch << 16 ;
        sof = sof + ch;
        ch = getchar();
        putchar(ch);
        ch = ch << 24;
        sof = sof + ch;
        fprintf (stderr, "size of file : %ld\n", sof);
        count = 0;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 'W')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 'A')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 'V')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 'E')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"WAVE\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 'f')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 'm')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 't')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != ' ')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"fmt\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        format = ch;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 8 ;
        format = format + ch ;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 16 ;
        format = format + ch;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 24;
        format = format + ch;
        fprintf(stderr, "size of format chucnck: %d\n", format);
        if (format != 16)
        {
            fprintf (stderr, "Error! size of format chunck should be 16\n");
            return(-1);
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        wavef = ch;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 8 ;
        wavef = wavef + ch ;
        fprintf(stderr, "WAVE type format: %d\n", wavef);
        if (wavef != 1)
        {
            fprintf (stderr, "Error! WAVE type format should be 1\n");
            return(-1);
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        stereo = ch;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 8 ;
        stereo = stereo + ch ;
        fprintf(stderr, "mono/stereo: %d\n", stereo);
        if ((stereo != 1) && (stereo != 2))
        {
            fprintf (stderr, "Error! mono/stereo should be 1 or 2\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        samplerate = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        samplerate = samplerate + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        samplerate = samplerate + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        samplerate = samplerate + ch;
        fprintf(stderr, "samplerate: %ld\n", samplerate);
        temp1 = samplerate * 2; /*  To mono pou allazei einai oti edw diplasiiazoume*/
        d4 = temp1 >> 24;
        temp1 = temp1 - (d4 << 24);
        d3 = temp1 >> 16;
        temp1 = temp1 - (d3 << 16);
        d2 = temp1 >> 8;
        temp1 = temp1 - (d2 << 8);
        d1 = temp1;
        putchar(d1);
        putchar(d2);
        putchar(d3);
        putchar(d4);
        ch = getchar();
        count = count + 1;
        bytesps = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        bytesps = bytesps + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        bytesps = bytesps + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        bytesps = bytesps + ch;
        fprintf(stderr, "bytes/sec: %ld\n", bytesps);
        temp1 = bytesps * 2; /*Omoia kai edw gia na isxei i eksiswsi pali*/
        d4 = temp1 >> 24;
        temp1 = temp1 - (d4 << 24);
        d3 = temp1 >> 16;
        temp1 = temp1 - (d3 << 16);
        d2 = temp1 >> 8;
        temp1 = temp1 - (d2 << 8);
        d1 = temp1;
        putchar(d1);
        putchar(d2);
        putchar(d3);
        putchar(d4);
        ch = getchar();
        putchar(ch);
        count = count + 1;
        blockal = ch;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 8 ;
        blockal = blockal + ch ;
        fprintf(stderr, "block alignment: %d\n", blockal);
        if (bytesps != (samplerate * blockal))
        {
            fprintf (stderr, "Error! bytes/second should be sample rate x block alignment\n");
            return(-1);
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        bitsps = ch;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 8 ;
        bitsps = bitsps + ch ;
        fprintf(stderr, "bits/sample: %d\n", bitsps);
        if ((bitsps != 8) && (bitsps != 16))
        {
            fprintf (stderr, "Error! bits/sampe should be 8 or 16\n");
            return(-1);
        }
        if (blockal != ((bitsps/8) * stereo))
        {
            fprintf (stderr, "Error! block allignment should be bits per sample / 8 x mono/stereo\n");
            return(-1);
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 'd')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 'a')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 't')
        {
            flag = 0;
        }
        ch = getchar();
        putchar(ch);
        count = count + 1;
        if (ch != 'a')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"data\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        sizeofdata = ch;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 8 ;
        sizeofdata = sizeofdata + ch ;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 16 ;
        sizeofdata = sizeofdata + ch;
        ch = getchar();
        putchar(ch);
        count = count + 1;
        ch = ch << 24;
        sizeofdata = sizeofdata + ch;
        fprintf(stderr, "size of data chunk: %ld\n", sizeofdata);
        cdistance = count;
        while (ch != EOF)
        {
            ch = getchar();
            if (ch != EOF)
            {
                putchar(ch);
                count = count + 1;
            }
        }
        if (sizeofdata > (count - cdistance))
        {
            fprintf(stderr, "Error! insufficient data\n");
            return(-1);
        }
        if(sof != count)
        {
            fprintf(stderr, "Error! bad file size\n");
            return(-1);
        }
        return 0;
    }
    if (MODE == 4)
    {
        flag = 1;
        ch = getchar();
        if (ch != 'R')
        {
            flag = 0;
        }
        ch = getchar();
        if (ch != 'I')
        {
            flag = 0;
        }
        ch = getchar();
        if (ch != 'F')
        {
            flag = 0;
        }
        ch = getchar();
        if (ch != 'F')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"RIFF\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        sof = ch;
        ch = getchar();
        ch = ch << 8 ;
        sof = sof + ch ;
        ch = getchar();
        ch = ch << 16 ;
        sof = sof + ch;
        ch = getchar();
        ch = ch << 24;
        sof = sof + ch;
        fprintf (stderr, "size of file : %ld\n", sof);
        count = 0;
        ch = getchar();
        count = count + 1;
        if (ch != 'W')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'A')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'V')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'E')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"WAVE\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        count = count + 1;
        if (ch != 'f')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'm')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 't')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != ' ')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"fmt\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        count = count + 1;
        format = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        format = format + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        format = format + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        format = format + ch;
        fprintf(stderr, "size of format chucnck: %d\n", format);
        if (format != 16)
        {
            fprintf (stderr, "Error! size of format chunck should be 16\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        wavef = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        wavef = wavef + ch ;
        fprintf(stderr, "WAVE type format: %d\n", wavef);
        if (wavef != 1)
        {
            fprintf (stderr, "Error! WAVE type format should be 1\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        stereo = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        stereo = stereo + ch ;
        fprintf(stderr, "mono/stereo: %d\n", stereo);
        if ((stereo != 1) && (stereo != 2))
        {
            fprintf (stderr, "Error! mono/stereo should be 1 or 2\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        samplerate = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        samplerate = samplerate + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        samplerate = samplerate + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        samplerate = samplerate + ch;
        fprintf(stderr, "samplerate: %ld\n", samplerate);
        ch = getchar();
        count = count + 1;
        bytesps = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        bytesps = bytesps + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        bytesps = bytesps + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        bytesps = bytesps + ch;
        fprintf(stderr, "bytes/sec: %ld\n", bytesps);
        ch = getchar();
        count = count + 1;
        blockal = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        blockal = blockal + ch ;
        fprintf(stderr, "block alignment: %d\n", blockal);
        if (bytesps != (samplerate * blockal))
        {
            fprintf (stderr, "Error! bytes/second should be sample rate x block alignment\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        bitsps = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        bitsps = bitsps + ch ;
        fprintf(stderr, "bits/sample: %d\n", bitsps);
        if ((bitsps != 8) && (bitsps != 16))
        {
            fprintf (stderr, "Error! bits/sampe should be 8 or 16\n");
            return(-1);
        }
        if (blockal != ((bitsps/8) * stereo))
        {
            fprintf (stderr, "Error! block allignment should be bits per sample / 8 x mono/stereo\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'd')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'a')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 't')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'a')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"data\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        count = count + 1;
        sizeofdata = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        sizeofdata = sizeofdata + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        sizeofdata = sizeofdata + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        sizeofdata = sizeofdata + ch;
        fprintf(stderr, "size of data chunk: %ld\n", sizeofdata);
        cdistance = count;
        putchar('R'); /*Ksekiname tin ektipwsi oso pio meta mporoume gia na ypologisoume tis apaitoumenes allages*/
        putchar('I');
        putchar('F');
        putchar('F');
        rubbish = sof - sizeofdata -36; /*Ypologismos megethous dedomenon pou de mas endiaferoun*/
        if (stereo == 2)    /*Periptosi pou tha allaksoume ta dedomena ixou*/
        {
            sizeofdata = sizeofdata / 2;    /*Ypodiplasiasmos dedomenon ixou*/
            sof = sizeofdata + 36 + rubbish;    /*Ypologismos tou size of file*/
            stereo = 1;
            bytesps = bytesps / 2;  /*Ypodiplasiamos bytes per second(ena kanali anti gia dyo)*/
            blockal = blockal / 2;  /*Rithmisi toy block alliance afou to sample rate menei stathero*/
            temp1 = sof;
            d4 = temp1 >> 24;   /* Idios tropos ektypwsis*/
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);
            putchar('W');
            putchar('A');
            putchar('V');
            putchar('E');
            putchar('f');
            putchar('m');
            putchar('t');
            putchar(' ');
            temp1 = format;
            d4 = temp1 >> 24;
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);
            temp1 = wavef;
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            temp1 = stereo;
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            temp1 = samplerate;
            d4 = temp1 >> 24;
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);
            temp1 = bytesps;
            d4 = temp1 >> 24;
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);
            temp1 = blockal;
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            temp1 = bitsps;
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar('d');
            putchar('a');
            putchar('t');
            putchar('a');
            temp1 = sizeofdata;
            d4 = temp1 >> 24;
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);
            while (((count + 1) - cdistance) <= (sizeofdata*2)) /*Elegos gia ftasoume mexri to telos tou arxikou size of data*/
            {
                for (i = 1; i <= (bitsps/8); i++) /* me vima analogo tou bit per sample*/
                {
                    ch = getchar();
                    if (ch != EOF) /*Elegxos gia EOF prin to telos tou size of data*/
                    {
                        putchar(ch); /*Edw ekpypwnoume (aristero kanali)*/
                        count = count + 1;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                    
                }
                if (flag == 0)
                {
                    break;
                }
                for (i = 1; i <= (bitsps/8); i++)
                {
                    ch = getchar();
                    if (ch != EOF)
                    {
                        count = count + 1; /*Edw den ektipwnoume (deksi kanali)*/
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 0)
                {
                    break;
                }   
            }
            flag = 1;
            while (ch != EOF)
            {
                ch = getchar();
                if (ch != EOF)
                {
                    putchar(ch); /*Ektipwnoume tyxon epipleon xaraktires meta ton ixo*/
                    count = count + 1;
                }
            }
            if ((sizeofdata*2) > (count - cdistance)) /*Elegxos gia eparki arxiko size of data*/
            {
                fprintf(stderr, "Error! insufficient data\n");
                return(-1);
            }
            if(((sizeofdata * 2) + rubbish  + cdistance) != count) /*Elegxos gia arxiko size of file*/
            {
                fprintf(stderr, "Error! bad file size\n");
                return(-1);
            }
        }
        else /*edw de peirazoume tipota*/
        {
            temp1 = sof;
            d4 = temp1 >> 24;
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);
            putchar('W');
            putchar('A');
            putchar('V');
            putchar('E');
            putchar('f');
            putchar('m');
            putchar('t');
            putchar(' ');
            temp1 = format;
            d4 = temp1 >> 24;
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);
            temp1 = wavef;
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            temp1 = stereo;
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            temp1 = samplerate;
            d4 = temp1 >> 24;
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);
            temp1 = bytesps;
            d4 = temp1 >> 24;
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);
            temp1 = blockal;
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            temp1 = bitsps;
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar('d');
            putchar('a');
            putchar('t');
            putchar('a');
            temp1 = sizeofdata;
            d4 = temp1 >> 24;
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);  
            while (ch != EOF)
            {
                ch = getchar();
                if (ch != EOF)
                {
                    putchar(ch);
                    count = count + 1;
                }
            }
            if (sizeofdata > (count - cdistance))
            {
                fprintf(stderr, "Error! insufficient data\n");
                return(-1);
            }
            if(sof != count)
            {
                fprintf(stderr, "Error! bad file size\n");
                return(-1);
            }
        }
        return 0;        
    }
    if (MODE == 5)
    {
        flag = 1;
        ch = getchar();
        if (ch != 'R')
        {
            flag = 0;
        }
        ch = getchar();
        if (ch != 'I')
        {
            flag = 0;
        }
        ch = getchar();
        if (ch != 'F')
        {
            flag = 0;
        }
        ch = getchar();
        if (ch != 'F')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"RIFF\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        sof = ch;
        ch = getchar();
        ch = ch << 8 ;
        sof = sof + ch ;
        ch = getchar();
        ch = ch << 16 ;
        sof = sof + ch;
        ch = getchar();
        ch = ch << 24;
        sof = sof + ch;
        fprintf (stderr, "size of file : %ld\n", sof);
        count = 0;
        ch = getchar();
        count = count + 1;
        if (ch != 'W')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'A')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'V')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'E')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"WAVE\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        count = count + 1;
        if (ch != 'f')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'm')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 't')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != ' ')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"fmt\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        count = count + 1;
        format = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        format = format + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        format = format + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        format = format + ch;
        fprintf(stderr, "size of format chucnck: %d\n", format);
        if (format != 16)
        {
            fprintf (stderr, "Error! size of format chunck should be 16\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        wavef = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        wavef = wavef + ch ;
        fprintf(stderr, "WAVE type format: %d\n", wavef);
        if (wavef != 1)
        {
            fprintf (stderr, "Error! WAVE type format should be 1\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        stereo = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        stereo = stereo + ch ;
        fprintf(stderr, "mono/stereo: %d\n", stereo);
        if ((stereo != 1) && (stereo != 2))
        {
            fprintf (stderr, "Error! mono/stereo should be 1 or 2\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        samplerate = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        samplerate = samplerate + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        samplerate = samplerate + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        samplerate = samplerate + ch;
        fprintf(stderr, "samplerate: %ld\n", samplerate);
        ch = getchar();
        count = count + 1;
        bytesps = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        bytesps = bytesps + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        bytesps = bytesps + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        bytesps = bytesps + ch;
        fprintf(stderr, "bytes/sec: %ld\n", bytesps);
        ch = getchar();
        count = count + 1;
        blockal = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        blockal = blockal + ch ;
        fprintf(stderr, "block alignment: %d\n", blockal);
        if (bytesps != (samplerate * blockal))
        {
            fprintf (stderr, "Error! bytes/second should be sample rate x block alignment\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        bitsps = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        bitsps = bitsps + ch ;
        fprintf(stderr, "bits/sample: %d\n", bitsps);
        if ((bitsps != 8) && (bitsps != 16))
        {
            fprintf (stderr, "Error! bits/sampe should be 8 or 16\n");
            return(-1);
        }
        if (blockal != ((bitsps/8) * stereo))
        {
            fprintf (stderr, "Error! block allignment should be bits per sample / 8 x mono/stereo\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'd')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'a')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 't')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'a')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"data\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        count = count + 1;
        sizeofdata = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        sizeofdata = sizeofdata + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        sizeofdata = sizeofdata + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        sizeofdata = sizeofdata + ch;
        fprintf(stderr, "size of data chunk: %ld\n", sizeofdata);
        cdistance = count;
        putchar('R');
        putchar('I');
        putchar('F');
        putchar('F');
        rubbish = sof - sizeofdata -36;
        if (stereo == 2)
        {
            sizeofdata = sizeofdata / 2;
            sof = sizeofdata + 36 + rubbish;
            stereo = 1;
            bytesps = bytesps / 2;
            blockal = blockal / 2;
            temp1 = sof;
            d4 = temp1 >> 24;
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);
            putchar('W');
            putchar('A');
            putchar('V');
            putchar('E');
            putchar('f');
            putchar('m');
            putchar('t');
            putchar(' ');
            temp1 = format;
            d4 = temp1 >> 24;
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);
            temp1 = wavef;
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            temp1 = stereo;
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            temp1 = samplerate;
            d4 = temp1 >> 24;
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);
            temp1 = bytesps;
            d4 = temp1 >> 24;
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);
            temp1 = blockal;
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            temp1 = bitsps;
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar('d');
            putchar('a');
            putchar('t');
            putchar('a');
            temp1 = sizeofdata;
            d4 = temp1 >> 24;
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);
            while (((count + 1) - cdistance) <= (sizeofdata*2))
            {
                for (i = 1; i <= (bitsps/8); i++)
                {
                    ch = getchar();
                    if (ch != EOF)
                    {
                        count = count + 1; /*Edw paraleipoume to aristero*/
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                    
                }
                if (flag == 0)
                {
                    break;
                }
                for (i = 1; i <= (bitsps/8); i++)
                {
                    ch = getchar();
                    if (ch != EOF)
                    {
                        putchar(ch);    /*Kai ektyponoume to deksi kanali*/
                        count = count + 1;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 0)
                {
                    break;
                }   
            }
            flag = 1;
            while (ch != EOF)
            {
                ch = getchar();
                if (ch != EOF)
                {
                    putchar(ch);
                    count = count + 1;
                }
            }
            if ((sizeofdata*2) > (count - cdistance))
            {
                fprintf(stderr, "Error! insufficient data\n");
                return(-1);
            }
            if(((sizeofdata * 2) + rubbish  + cdistance) != count)
            {
                fprintf(stderr, "Error! bad file size\n");
                return(-1);
            }
        }
        else
        {
            temp1 = sof;
            d4 = temp1 >> 24;
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);
            putchar('W');
            putchar('A');
            putchar('V');
            putchar('E');
            putchar('f');
            putchar('m');
            putchar('t');
            putchar(' ');
            temp1 = format;
            d4 = temp1 >> 24;
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);
            temp1 = wavef;
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            temp1 = stereo;
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            temp1 = samplerate;
            d4 = temp1 >> 24;
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);
            temp1 = bytesps;
            d4 = temp1 >> 24;
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);
            temp1 = blockal;
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            temp1 = bitsps;
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar('d');
            putchar('a');
            putchar('t');
            putchar('a');
            temp1 = sizeofdata;
            d4 = temp1 >> 24;
            temp1 = temp1 - (d4 << 24);
            d3 = temp1 >> 16;
            temp1 = temp1 - (d3 << 16);
            d2 = temp1 >> 8;
            temp1 = temp1 - (d2 << 8);
            d1 = temp1;
            putchar(d1);
            putchar(d2);
            putchar(d3);
            putchar(d4);  
            while (ch != EOF)
            {
                ch = getchar();
                if (ch != EOF)
                {
                    putchar(ch);
                    count = count + 1;
                }
            }
            if (sizeofdata > (count - cdistance))
            {
                fprintf(stderr, "Error! insufficient data\n");
                return(-1);
            }
            if(sof != count)
            {
                fprintf(stderr, "Error! bad file size\n");
                return(-1);
            }
        }
        return 0;        
    }
    if (MODE == 6)
    {
        flag = 1;
        ch = getchar();
        if (ch != 'R')
        {
            flag = 0;
        }
        ch = getchar();
        if (ch != 'I')
        {
            flag = 0;
        }
        ch = getchar();
        if (ch != 'F')
        {
            flag = 0;
        }
        ch = getchar();
        if (ch != 'F')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"RIFF\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        sof = ch;
        ch = getchar();
        ch = ch << 8 ;
        sof = sof + ch ;
        ch = getchar();
        ch = ch << 16 ;
        sof = sof + ch;
        ch = getchar();
        ch = ch << 24;
        sof = sof + ch;
        fprintf (stderr, "size of file : %ld\n", sof);
        count = 0;
        ch = getchar();
        count = count + 1;
        if (ch != 'W')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'A')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'V')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'E')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"WAVE\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        count = count + 1;
        if (ch != 'f')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'm')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 't')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != ' ')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"fmt\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        count = count + 1;
        format = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        format = format + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        format = format + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        format = format + ch;
        fprintf(stderr, "size of format chucnck: %d\n", format);
        if (format != 16)
        {
            fprintf (stderr, "Error! size of format chunck should be 16\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        wavef = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        wavef = wavef + ch ;
        fprintf(stderr, "WAVE type format: %d\n", wavef);
        if (wavef != 1)
        {
            fprintf (stderr, "Error! WAVE type format should be 1\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        stereo = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        stereo = stereo + ch ;
        fprintf(stderr, "mono/stereo: %d\n", stereo);
        if ((stereo != 1) && (stereo != 2))
        {
            fprintf (stderr, "Error! mono/stereo should be 1 or 2\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        samplerate = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        samplerate = samplerate + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        samplerate = samplerate + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        samplerate = samplerate + ch;
        fprintf(stderr, "samplerate: %ld\n", samplerate);
        ch = getchar();
        count = count + 1;
        bytesps = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        bytesps = bytesps + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        bytesps = bytesps + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        bytesps = bytesps + ch;
        fprintf(stderr, "bytes/sec: %ld\n", bytesps);
        ch = getchar();
        count = count + 1;
        blockal = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        blockal = blockal + ch ;
        fprintf(stderr, "block alignment: %d\n", blockal);
        if (bytesps != (samplerate * blockal))
        {
            fprintf (stderr, "Error! bytes/second should be sample rate x block alignment\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        bitsps = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        bitsps = bitsps + ch ;
        fprintf(stderr, "bits/sample: %d\n", bitsps);
        if ((bitsps != 8) && (bitsps != 16))
        {
            fprintf (stderr, "Error! bits/sampe should be 8 or 16\n");
            return(-1);
        }
        if (blockal != ((bitsps/8) * stereo))
        {
            fprintf (stderr, "Error! block allignment should be bits per sample / 8 x mono/stereo\n");
            return(-1);
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'd')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'a')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 't')
        {
            flag = 0;
        }
        ch = getchar();
        count = count + 1;
        if (ch != 'a')
        {
            flag = 0;
        }
        if (flag == 0)
        {
           fprintf(stderr, "Error! \"data\" not found\n");
           return(-1);
        }
        flag = 1;
        ch = getchar();
        count = count + 1;
        sizeofdata = ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 8 ;
        sizeofdata = sizeofdata + ch ;
        ch = getchar();
        count = count + 1;
        ch = ch << 16 ;
        sizeofdata = sizeofdata + ch;
        ch = getchar();
        count = count + 1;
        ch = ch << 24;
        sizeofdata = sizeofdata + ch;
        fprintf(stderr, "size of data chunk: %ld\n", sizeofdata);
        cdistance = count;
        putchar('R');
        putchar('I');
        putchar('F');
        putchar('F');
        rubbish = sof - sizeofdata -36;
        temp1 = sof;
        d4 = temp1 >> 24;
        temp1 = temp1 - (d4 << 24);
        d3 = temp1 >> 16;
        temp1 = temp1 - (d3 << 16);
        d2 = temp1 >> 8;
        temp1 = temp1 - (d2 << 8);
        d1 = temp1;
        putchar(d1);
        putchar(d2);
        putchar(d3);
        putchar(d4);
        putchar('W');
        putchar('A');
        putchar('V');
        putchar('E');
        putchar('f');
        putchar('m');
        putchar('t');
        putchar(' ');
        temp1 = format;
        d4 = temp1 >> 24;
        temp1 = temp1 - (d4 << 24);
        d3 = temp1 >> 16;
        temp1 = temp1 - (d3 << 16);
        d2 = temp1 >> 8;
        temp1 = temp1 - (d2 << 8);
        d1 = temp1;
        putchar(d1);
        putchar(d2);
        putchar(d3);
        putchar(d4);
        temp1 = wavef;
        d2 = temp1 >> 8;
        temp1 = temp1 - (d2 << 8);
        d1 = temp1;
        putchar(d1);
        putchar(d2);
        temp1 = stereo;
        d2 = temp1 >> 8;
        temp1 = temp1 - (d2 << 8);
        d1 = temp1;
        putchar(d1);
        putchar(d2);
        temp1 = samplerate;
        d4 = temp1 >> 24;
        temp1 = temp1 - (d4 << 24);
        d3 = temp1 >> 16;
        temp1 = temp1 - (d3 << 16);
        d2 = temp1 >> 8;
        temp1 = temp1 - (d2 << 8);
        d1 = temp1;
        putchar(d1);
        putchar(d2);
        putchar(d3);
        putchar(d4);
        temp1 = bytesps;
        d4 = temp1 >> 24;
        temp1 = temp1 - (d4 << 24);
        d3 = temp1 >> 16;
        temp1 = temp1 - (d3 << 16);
        d2 = temp1 >> 8;
        temp1 = temp1 - (d2 << 8);
        d1 = temp1;
        putchar(d1);
        putchar(d2);
        putchar(d3);
        putchar(d4);
        temp1 = blockal;
        d2 = temp1 >> 8;
        temp1 = temp1 - (d2 << 8);
        d1 = temp1;
        putchar(d1);
        putchar(d2);
        temp1 = bitsps;
        d2 = temp1 >> 8;
        temp1 = temp1 - (d2 << 8);
        d1 = temp1;
        putchar(d1);
        putchar(d2);
        putchar('d');
        putchar('a');
        putchar('t');
        putchar('a');
        temp1 = sizeofdata;
        d4 = temp1 >> 24;
        temp1 = temp1 - (d4 << 24);
        d3 = temp1 >> 16;
        temp1 = temp1 - (d3 << 16);
        d2 = temp1 >> 8;
        temp1 = temp1 - (d2 << 8);
        d1 = temp1;
        putchar(d1);
        putchar(d2);
        putchar(d3);
        putchar(d4);
        while (((count + 1) - cdistance) <= (sizeofdata))
        {
            if (bitsps == 16) /*Periptwsi 16 samplerate*/
            {
                ch = getchar();
                if(ch == EOF)
                {
                    break;
                }
                count = count + 1;
                temp1 = ch;
                ch = getchar();
                if (ch == EOF)
                {
                    flag = 0;
                }
                count = count + 1;
                ch = ch << 8 ;
                temp1 = temp1 + ch ; /*Edw exoume dimiourgisei tin aksi tou arithmou me ton idio tropo*/
                if (temp1 > 32767)  /*Sinthiki arnitikou i thetikou*/
                {
                    temp1 = 65536 - temp1; /*Ypologismos apolitis timis arnitikou arithmou mesw apostasis apo ti mikroteri dinati apoliti timi*/ 
                    temp1 = temp1 / 8;      /*Diairesi tis timis me to 8*/
                    temp1 = 65536 - temp1;  /*Metatropi ston antistoixo arnitiko arithmo pali mesw apostasis*/
                }
                else
                {
                    temp1 = temp1 / 8;  /*Gia thetikous arithmous arkei mono i diaresi*/
                }
                d2 = temp1 >> 8;
                temp1 = temp1 - (d2 << 8);
                d1 = temp1;
                putchar(d1);
                if (flag == 0)
                {
                    break;
                }
                putchar(d2);
            }
            else if(bitsps == 8)
            {
                ch = getchar();
                if (ch != EOF)
                {
                    count = count + 1;
                    temp1 = ch;
                    temp1 = temp1 /8; /*Oi 8bitoi einai panta thetikoi ara mono diairesi*/
                    d1 = temp1;
                    putchar(d1);
                }
                else
                {
                    break;
                }
                
            }   
        }
        flag = 1;
        while (ch != EOF)
        {
            ch = getchar();
            if (ch != EOF)
            {
                putchar(ch);
                count = count + 1;
            }
        }
        if (sizeofdata > (count - cdistance))
        {
            fprintf(stderr, "Error! insufficient data\n");
            return(-1);
        }
        if(sof != count)
        {
            fprintf(stderr, "Error! bad file size\n");
            return(-1);
        }
        return 0;
    }
    if (MODE == 7)
    {
        mysound(3, 44100, 2.0, 1500.0, 100.0, 30000.0); /*Klisi sinartisis me ta orismata*/
        return 0;
    }
}

void mysound(int dur, int sr, double fm, double fc, double mi, double mv)
{
    long sof, samplerate, bytesps, sizeofdata;
    int k, format, wavef, stereo, blockal, bitsps, d1, d2, d3, d4, temp1;
    double p, t;
    k = 0;
    putchar('R'); /*Ektiponoumw prodiagrafes nomimou arxeiou*/
    putchar('I');
    putchar('F');
    putchar('F');
    sof = 264636;
    temp1 = sof;
    d4 = temp1 >> 24;
    temp1 = temp1 - (d4 << 24);
    d3 = temp1 >> 16;
    temp1 = temp1 - (d3 << 16);
    d2 = temp1 >> 8;
    temp1 = temp1 - (d2 << 8);
    d1 = temp1;
    putchar(d1);
    putchar(d2);
    putchar(d3);
    putchar(d4);
    putchar('W');
    putchar('A');
    putchar('V');
    putchar('E');
    putchar('f');
    putchar('m');
    putchar('t');
    putchar(' ');
    format = 16;
    temp1 = format;
    d4 = temp1 >> 24;
    temp1 = temp1 - (d4 << 24);
    d3 = temp1 >> 16;
    temp1 = temp1 - (d3 << 16);
    d2 = temp1 >> 8;
    temp1 = temp1 - (d2 << 8);
    d1 = temp1;
    putchar(d1);
    putchar(d2);
    putchar(d3);
    putchar(d4);
    wavef = 1;
    temp1 = wavef;
    d2 = temp1 >> 8;
    temp1 = temp1 - (d2 << 8);
    d1 = temp1;
    putchar(d1);
    putchar(d2);
    stereo = 1;
    temp1 = stereo;
    d2 = temp1 >> 8;
    temp1 = temp1 - (d2 << 8);
    d1 = temp1;
    putchar(d1);
    putchar(d2);
    samplerate = 44100;
    temp1 = samplerate;
    d4 = temp1 >> 24;
    temp1 = temp1 - (d4 << 24);
    d3 = temp1 >> 16;
    temp1 = temp1 - (d3 << 16);
    d2 = temp1 >> 8;
    temp1 = temp1 - (d2 << 8);
    d1 = temp1;
    putchar(d1);
    putchar(d2);
    putchar(d3);
    putchar(d4);
    bytesps = 88200;
    temp1 = bytesps;
    d4 = temp1 >> 24;
    temp1 = temp1 - (d4 << 24);
    d3 = temp1 >> 16;
    temp1 = temp1 - (d3 << 16);
    d2 = temp1 >> 8;
    temp1 = temp1 - (d2 << 8);
    d1 = temp1;
    putchar(d1);
    putchar(d2);
    putchar(d3);
    putchar(d4);
    blockal = 2;
    temp1 = blockal;
    d2 = temp1 >> 8;
    temp1 = temp1 - (d2 << 8);
    d1 = temp1;
    putchar(d1);
    putchar(d2);
    bitsps = 16;
    temp1 = bitsps;
    d2 = temp1 >> 8;
    temp1 = temp1 - (d2 << 8);
    d1 = temp1;
    putchar(d1);
    putchar(d2);
    putchar('d');
    putchar('a');
    putchar('t');
    putchar('a');
    sizeofdata = 264600;
    temp1 = sizeofdata;
    d4 = temp1 >> 24;
    temp1 = temp1 - (d4 << 24);
    d3 = temp1 >> 16;
    temp1 = temp1 - (d3 << 16);
    d2 = temp1 >> 8;
    temp1 = temp1 - (d2 << 8);
    d1 = temp1;
    putchar(d1);
    putchar(d2);
    putchar(d3);
    putchar(d4);
    for (p = 0.0 ; p<= (dur * sr); p = (p + (1/(double)sr))) /*Domi epanalipsis ipologismou sinartisis*/
    {
        t = mv * sin((2 * M_PI * fc * p) -( mi * (sin(2 * M_PI * fm * p))));
        temp1 = (int)t;
        d2 = temp1 >> 8;
        temp1 = temp1 - (d2 << 8);
        d1 = temp1;
        putchar(d1);
        putchar(d2); /* Ektipwsi se dyo xaraktires opws sta prohgoumena kommatia tou programmatos*/
        k = k +2; /*Metritis xaraktirwn me vima 2*/
        if (k == (dur * sr * 2)) /*Otan paroume ta dedomena pou theloume stamatame*/
        {
            break;
        }
    }    
}
