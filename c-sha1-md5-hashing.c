public class Hash
{
public string SHA1(string input)
{
byte[] hash;
using (var sha1 = new System.Security.Cryptography.SHA1CryptoServiceProvider())
{
hash = sha1.ComputeHash(Encoding.Unicode.GetBytes(input));
}
var sb = new StringBuilder();
foreach (byte b in hash) sb.AppendFormat("{0:x2}", b);
return sb.ToString();
}
public string MD5(string input)
{
MD5 md5 = new MD5CryptoServiceProvider();
string pass = Console.ReadLine();
byte[] checkSum = md5.ComputeHash(Encoding.Unicode.GetBytes(input));
string result = BitConverter.ToString(checkSum).Replace("-", String.Empty);
return result.ToLower();
}
}
