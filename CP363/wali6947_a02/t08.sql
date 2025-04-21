SELECT 
    CONCAT(m.memberForename, ' ', m.memberSurname) AS fullMemberName,
    COUNT(mb.memberBroadBroadId) AS numberOfBroadExpertises
FROM 
    member m
JOIN 
    memberBroad mb ON m.memberId = mb.memberBroadMemberId
JOIN 
    broad b ON mb.memberBroadMemberId  = b.broadId
GROUP BY 
    fullMemberName
ORDER BY 
    fullMemberName;
