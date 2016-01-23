import os
import copy

def findFirstChar(first_char, board, visited):
    position_list = []
    row_num = len(board)
    col_num = len(board[0])
    for i in range(row_num):
        for j in range(col_num):
            if first_char == board[i][j] and visited[i][j] == False:
                pos = (i, j)
                tmp_visited = copy.deepcopy(visited)
                tmp_visited[i][j] = True
                position_list += [(pos, tmp_visited)]
    return position_list

def findFirstCharAround(first_char, board, position, visited):
    position_list = []
    row_num = len(board)
    col_num = len(board[0])
    (i,j) = position
    if i-1 >= 0 and board[i-1][j] == first_char and visited[i-1][j] == False:
        tmp_visited = copy.deepcopy(visited)
        tmp_visited[i-1][j] = True
        position_list += [((i-1, j), tmp_visited)]
    if j-1 >= 0 and board[i][j-1] == first_char and visited[i][j-1] == False:
        tmp_visited = copy.deepcopy(visited)
        tmp_visited[i][j-1] = True
        position_list += [((i, j-1), tmp_visited)]
    if i+1 < row_num  and board[i+1][j] == first_char and visited[i+1][j] == False:
        tmp_visited = copy.deepcopy(visited)
        tmp_visited[i+1][j] = True
        position_list += [((i+1, j), tmp_visited)]
    if j+1 < col_num  and board[i][j+1] == first_char and visited[i][j+1] == False:
        tmp_visited = copy.deepcopy(visited)
        tmp_visited[i][j+1] = True
        position_list += [((i, j+1), tmp_visited)]

    return position_list


def findNextStep(board, word, position, visited):
    if len(word) == 0:
        return True
    first_char = word[0]
    word = word[1:]

    position_list = []
    if position == None:
        position_list = findFirstChar(first_char, board, visited)
    else:
        position_list = findFirstCharAround(first_char, board, position, visited)

    ret = False
    for item in position_list:
        ret = (ret or findNextStep(board, word, item[0], item[1]))

    return ret


def exist(board, word):
    """
    Time exceeded, have a space to improve
    """
    row_num = len(board)
    col_num = len(board[0])
    visited = [None] * row_num
    for i in range(row_num):
        visited[i] = [False] * col_num
    return findNextStep(board, word, None, visited)

def main():
    board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]
    if (exist(board, 'ABCCED')):
        print 'Yes'
    else:
        print 'No'

    if (exist(board, 'SEE')):
        print 'Yes'
    else:
        print 'No'

    if (exist(["vpyiswkmdrpuetjwroerzxnchenphfqexpmpnxdsqvmuqxqhnwbouoqdsfsbnlgkcubpthjjcvdsuwchsdvorou",
               "lvoniztubpwsjdbshyybuwdbqgzfzpblkpyvptpsilnrqqmxpkbjgenwlodkfexpuvmlqcdbpssgjefaqglylyv",
               "yoakthildfxowztxpmrxxyexoninajkyxmittsewybmudgtuumtrkxobkyqkhckhovakneglhvhmbcgxpzqbzee",
               "leuymyitndvxtbfgkcoxdsdcjfslgyprdmprkamzfhyykgfuivropxqzelmkjddorvhcvtdaccbmiihsfaguxzv",
               "dmhnvntmeotgjpkltomgywpsbrzyratumdijqbxurrdaipnbdajdyavaswyjwtdkwnumqrjhkmhubxwgxfjxgex",
               "adxjztokpcgeszpakbjecgcifktfszescebexpootwuovjqhkbookqyparwsrbmvfpzchpqalnojweqhggvqxwh",
               "zneughgemwdqdtifgvupsaibioyanuinkojqxpujnabsvjybhutzwbafraffvpuffdxcuunkuoepaeshylgvoic",
               "ikjpfzjmeokjkewwanbrnfluexcbnmfxwomenxqunadygbuioxzddlxjkbmzprxoflsvlirylwyrxvaosbrvmrg",
               "yusykjxyriqotafulbsfanhogiidvzkttctfoqffbvvwyaqjdjqdwxuegciddsyywsekklrlhmkhoastljxigto",
               "ovwraqqankezwsrkzfuiwuapgjmqshegedaevqfkclkyddieicmezpuhyixssdzwizberiovvavbdefoiuujjqq",
               "jbncttdpbeshxcysyynzetgseamnlfexgtzzmeoqijxflvzjwmkagrsmtgzhlderxfslljbtszadwzpslbstumf",
               "ovhxgkdajisxtbyovzobwnqqatjwovdeqkbzxebiovfjzgzufnvdcnuehfcvagbtseurkvcyqhjrpimvxjabxuf",
               "gzkdcqexkiresogsgndydlmakvcluzscacfeulbhvulpirhrgmrlzdnjaqwxppzrtfwqsxxouidebnvhzmvzrik",
               "sahrryqjrxfhqeggyqjdryabynwzggjahsraqijkhotxvadtqpyinzlnmhmupyvyqozhyirgzmfumjpdaonnnab",
               "bjpvynsxejwnhggnfstbferkefztuzuvimsizlffudsdkytrtotysmkytlrnmoiwaaebnmhjrznbagvtuqtocfo",
               "vqhkcxsaxuebksitkjinjqiemyxcacqxuyhyvbyvwfwixgdhpmvbedfrefvehmeemlcjpbgngevfkyncmidrnkk",
               "rpfyztcdhpfteizrqgowsnjubtzsimeabmaafcdptliyvhrmpgkivvewoerwqxytjyurczgwmowkxpynvivsdzr",
               "tfirxhsrrqnkvoqrdgpndelscvpwyrntwxkwfepyveisualxgamjgxeisthskunjsyhzcwzzchrwhcupegalgev",
               "aycvkzittiasnytoaagxjktyrbyehfzkfefpdplwylqlmjzmlhlwuewngwrpbszgygybwjzwwrjickxpuilonhd",
               "veukfomonumqqvqorjxcmizbchpswwxrctekhqyukmndjdrcorecbdgflvzjtwbwpfgyxgvhsimdlefbxkeankf",
               "ahekacnwtserpmmyeuljhrpjozpoobvribdidqhyknpbaczgymqidfrtgijujgnrhqbmiikswcvwgxcejsmpzfk",
               "fnwawcnpkgryobjjxnevtbaxnumeurozhkbfnrvzxoxnpiwpvdmogmothaxdtoccyginxfmwvmlkwibunoktcyp",
               "jaomwcrydziqwpfukrfxppyjcouyruncxbrveithhezftebgxgdnwdwassylnlnmpehvocexgdecifihmlukqtk",
               "iljtawjmnnvicymbgsgiclsjxfejwzugkfandjbryxbcxoedgkoixgtxmzgkycqljsypdbgcyhevxkbfwppuxjr",
               "lizvhcoungscktimussrrduxbjmvjxougospsglfmdkwyukumdmeigdjsrhbpxxxnpofvznkexgctrzgwnmgtrr",
               "niyqxyqulfktdjinnhvsaorgkeuqzlipwiftgxqudanimvxzcsrchilrohkovudrekmniehnhuvtpsstkmvtwin",
               "lqxbnteezqsmyxvlepixgcrbndzichvpzuqmnwspmlbnixymojlxlcyyixjkhebgzrtopldbyhoggpsuyftjisk",
               "srtcyzffywannnsomzfshwnewsxfcpruhmyfmdmkbmzoasfotmgbivfeqelsudndrnkdrzqulpjnjqdfcmimhpq",
               "xtdspihuaufdngvitltjwjmdlylxicpfwszlbggddniqveaortxpcktpigmsjbafwzsziaelpmdkqezjzwzciur",
               "tagljjlqhllgtlkgdzjnrpmbplattwmmwsaielalylurzgzcflpxaeyrpakkwzzutzcxmdjlqfepletrpjorpoj",
               "govqmurgoslnfqyqgduyparipcwhrkszansokjuyefnjxmberxegyxopamytyqtaeloqwjqaqdlopouhmapmxgd",
               "zucttuotybkozteclknbbevkqvaevijuclnvidrggbxgwdijpxlrbibtedzbljvowlleoenvfmddrlnhiyykgzf",
               "mffnqojgkwspkyeheqkjhvwogwosfqxrvchnqsudoouamyisquczqaoyxescupvpucfmwzpmnlnbjxubrybjyrh",
               "vvzzsrvhlzoxynpkcaxemwanoaoxyfhwdixvzsekutksgzelzerlarzorpmrxvpadnxdhbpduzxdycoagflgymv",
               "rcjkzgabjpyoyzecwfzbebpejwrqwenniyzhebknqicrjitfnugtyxzhvrzrxmgfmioqjygagktpsoxfifzifys",
               "arruogctukhlwhtyndrfvfeapjbyocsrtlnkrrfmcpzywswmvprsuxsjgwjxabqtndfguluyavyynwkkldchaxt",
               "jvcgvgyqvdwbzjyajtyjjxuvkxasyxnhupppxpfssdwrmurxpshyrbwbawvavijpaygxpnshrobfiudxomyhnul",
               "pqgqlrzctaispvkzmycsgyxgpjewyahnqoddhdfafnsukdvzdxrkyqsnzwjzwrmohstqxaqcnkwzpuytrrfphxc",
               "ivohtfwjoocelcwnrglqyfrtziyosxtcujknogweuaiheeuvmfnklgfkpfajcvlygxludjyzligpmcmziclvith",
               "zyjidfwbltpizyiymrhdfjqgtuuocnvelfoomkszghhfhsftlmxsypzrjtgngdrtkgiwsawyjffqzlkkzjdzaer",
               "jzzwfcqynyilqkhrtpykojwblhgkhkdsjcqqhgqwebhxnrqhiotwarznafzhrdbchruoynmeowdbptkxkdvkwvz",
               "wcydubgyjytzwgocwkgzzzkylntxmqwitvopyuphsijqqxtohboicygonblzuiipfyedsvlngwdwtynczbkczsq",
               "ovdopnygswmwqijdofhmahzchcoldgbsdgivuibmeoiwytamajaaqaczeqkiynacukzosacyqnuogwchhdhadmz",
               "hcmrdzrfvdelvgotxdqnjmqsutcuyovhshzvjscewiqtrgnqjfdurvpnorjohhwbovzzpbelmwfdeutnzyjsuyi",
               "irtzyavcrsbqhewvqscvwyolznvthvbrnxqnxnpofshpzdmpyqlwobinqfizcmtpjjfgzuxepgvojjfjzsgpuqe",
               "mxnmzzfpiquqpqpwhvtxhddscvysrqwenlspkxgupalfsadcywzfzcxeayyrowxeiptuozpebalvcoxakzhmdhs",
               "dfqxvmwbwowrcxgiyitwkhvnuuugabydiqcgezhdngurdcackvawfvjzsghshhxszaydbhgqnchrejvqfvpksal",
               "kgueobciaegffpmvdqewxorpvoehifsvlmzbpdjrhrwohkjmbqiyebpbpuizbcuoqusfxbyhvuvehhqkxakdbze",
               "stmrwomleidlhgjodfmhotxysxivaizsdnmcdypjisupafggmsnbnnbfmmanubhzotdttscbmwrpdxvprisexwj",
               "kilzeoideejxxbzboxudatyrkimqgizsqmtuabxefgdfkcgyzcdbvdshnexvmynckiwmmwstevyozgoyitzfwtm",
               "myjhmhxptfnhrjznqwlgvuxveqwkpqybqiicrftnnhugsutkshrqbolfgkrvaqysahwrosgdbbmvxfgpmzfpptx",
               "vdqtfgrxgavapnguojgkgosyarfsgyrbbhuiomhwodydshajqgtxulxxecrkbinepknfwuemzesslsbcywbvjyu",
               "nalzbvmimwvuuryhtczlorosrktovriitvjxqvfducxovxxobwbrppjjbexwxigrdpownvbhxavsztjarkuhadq",
               "dkpahxiydaobnjcugcpbbkmdcwxlyddcnseusovxojybvavbenehzsmdpkoppttcmxygovdchbgcddfjskqsccx"],
               "oojdhcftcgbsbeu")):
        print 'Yes'
    else:
        print 'No'

if __name__ == '__main__':
    main()