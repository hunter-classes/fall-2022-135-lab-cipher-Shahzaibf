#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

// add your tests here
TEST_CASE("Caesar Shifts"){
    CHECK(encryptCaesar("Hello, World!", 10) == "Rovvy, Gybvn!");
    CHECK(encryptCaesar("To be or not to be, That is the question", 9) == "Cx kn xa wxc cx kn, Cqjc rb cqn zdnbcrxw");
}

TEST_CASE("Vigenere Cipher"){
    CHECK(encryptVigenere("Goodnight", "moon") == "Sccqzwuuf");
    CHECK(encryptVigenere("I LOVE CODE!","love") == "T ZJZP QJHP!");
}

TEST_CASE("DECRYPTIONS"){
    CHECK(decryptCaesar("Dtwgpc Xzzy.", 11) == "Silver Moon.");
    CHECK(decryptVigenere("Vpa krpi.", "decode") == "Sly wolf.");
}
TEST_CASE("Testing solve()") {
	std::string encrypted, solved;
	
	encrypted = "Ns uzgqnxmnsl fsi lwfumnh ijxnls, Qtwjr nuxzr nx f uqfhjmtqijw yjcy htrrtsqd zxji yt ijrtsxywfyj ymj anxzfq ktwr tk f ithzrjsy tw f ydujkfhj bnymtzy wjqdnsl ts rjfsnslkzq htsyjsy. Qtwjr nuxzr rfd gj zxji fx f uqfhjmtqijw gjktwj knsfq htud nx fafnqfgqj. Ny nx fqxt zxji yt yjrutwfwnqd wjuqfhj yjcy ns f uwthjxx hfqqji lwjjpnsl, bmnhm fqqtbx ijxnlsjwx yt htsxnijw ymj ktwr tk f bjguflj tw uzgqnhfynts, bnymtzy ymj rjfsnsl tk ymj yjcy nskqzjshnsl ymj ijxnls.";
	solved = "In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available. It is also used to temporarily replace text in a process called greeking, which allows designers to consider the form of a webpage or publication, without the meaning of the text influencing the design.";
	CHECK(solve(encrypted) == solved);
	
	encrypted = "Og gccb og W offwjsr wb hvs Wbrwsg, wb hvs twfgh wgzobr kvwqv W tcibr, W hccy gcas ct hvs bohwjsg pm tcfqs, wb cfrsf hvoh hvsm awuvh zsofb obr awuvh uwjs as wbtcfaohwcb ct kvohsjsf hvsfs wg wb hvsgs dofhg. Obr gc wh kog hvoh hvsm gccb ibrsfghccr ig, obr ks hvsa, swhvsf pm gdssqv cf pm gwubg, obr hvsm vojs pssb jsfm gsfjwqsopzs.";
	solved = "As soon as I arrived in the Indies, in the first island which I found, I took some of the natives by force, in order that they might learn and might give me information of whatever there is in these parts. And so it was that they soon understood us, and we them, either by speech or by signs, and they have been very serviceable.";
	CHECK(solve(encrypted) == solved);
}