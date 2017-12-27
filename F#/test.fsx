open System.Net
open System



let downloadUriToFile url targetfile =
    let req = WebRequest.Create(Uri(url))
    use resp = rep.GetResponse()


match fsi.CommandLineArgs with
    