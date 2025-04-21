SELECT 
    CONCAT(m.memberSurname, ' ', m.memberForename) AS fullMemberName,
    COUNT(mn.memberNarrowMemberId) AS numberOfNarrowExpertises
FROM 
    member m
LEFT JOIN 
    memberNarrow mn ON m.memberId = mn.memberNarrowMemberId
GROUP BY 
    m.memberId
ORDER BY 
    fullMemberName
