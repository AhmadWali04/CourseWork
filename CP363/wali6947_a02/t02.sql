SELECT 
    CONCAT(m.memberSurname, ' ', m.memberForename) AS fullMemberName,
    pt.pubTypeDesc AS fullPublicationType,
    p.pubTitle AS publicationTitle
FROM 
    member m
JOIN 
    pub p ON m.memberId = p.pubMemberId
JOIN 
    pubType pt ON p.pubPubType = pt.pubType
WHERE 
    m.memberInstitution LIKE '%Wilfrid Laurier%'
ORDER BY 
    fullMemberName;
