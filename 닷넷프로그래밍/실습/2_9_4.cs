using System;
class ExerciseCh2_9_4
{
    static void WriteLocation(byte[] ba)
    {
        unsafe
        {
            fixed (byte* pArray = ba)
            {
                byte* pElem = pArray;
                for(int i = 0; i < ba.Length; i++)
                {
                    byte value = *pElem;
                    Console.WriteLine("ba[{0}] at 0x{1:x} is {2}",
                        i, (uint)pElem, value);
                    pElem++;
                }
            }
        }
    }
    public static void Main()
    {
        byte[] ba = new byte[] { 1, 2, 3, 4, 5 };
        WriteLocation(ba);
    }
}
/*
 ba[0] at 0x9c2aab20 is 1
ba[1] at 0x9c2aab21 is 2
ba[2] at 0x9c2aab22 is 3
ba[3] at 0x9c2aab23 is 4
ba[4] at 0x9c2aab24 is 5
*/