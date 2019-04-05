function caeser(n, s)
{
    var alphabet = 'abcdefghijklmnopqrstuvwxyz';
    var result = '';

    for (var i = 0; i < s.length; i++)
    {
        if (alphabet.indexOf(s[i]) >= 0)
        {
            result += alphabet[(alphabet.indexOf(s[i]) + n) % 26];
        }
        else
        {
            result += s[i];
        }
    }

    return result;
}

console.log(caeser(13, 'uggcf://jjj.pyvsg.bet/serq/hnopvby833k__333__.ugzy'));
