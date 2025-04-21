SELECT 
    p.pubTitle AS publicationTitle,
    pt.pubTypeDesc AS fullPublicationType
FROM 
    member m
JOIN 
    pub p ON m.memberId = p.pubMemberId
JOIN 
    pubType pt ON p.pubPubType = pt.pubType
WHERE 
    m.memberSurname = 'Bain' AND m.memberForename = 'William'
ORDER BY 
    publicationTitle
